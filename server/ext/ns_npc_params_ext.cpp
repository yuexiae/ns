#include "server/server_pch.h"

#include "server/ext/ns_npc_params_ext.h"
#include "base/file_util.h"
#include <fstream>


bool CNSNpcParamsExt::ReadNpcScript(unsigned short wNpcId, CNSNpcParams::_NpcScript& script) {
	bool result = false;

	char filePath[MAX_PATH];
	sprintf(filePath, ".\\script\\%u.lua", wNpcId);

    base::FileReader reader_body(filePath);
    if (reader_body.IsSuccess()) {
        int require_npcid = 0;
        if (sscanf(reader_body.Get(), "require(\"%u\")", &require_npcid) == 1){
            result = ReadNpcScript(require_npcid, script);
            if (result == false){
                GameUtil::Output("ReadNpcScript npcid:%u copy npcid:%u failure\n", wNpcId, require_npcid);
            }
        } else {
            base::FileReader reader_head(".\\script\\0.lua");
            if (reader_head.IsSuccess()) {
                char *data = new char[reader_head.Size() + reader_body.Size() + 2];
                memcpy(data, reader_head.Get(), reader_head.Size());
                data[reader_head.Size()] = '\n';
                memcpy(data + reader_head.Size() + 1, reader_body.Get(), reader_body.Size());
                data[reader_head.Size() + reader_body.Size() + 1] = '\0';

                script.wNpcId = wNpcId;
                script.szScript = data;
                result = true;
            }
        }
    }

	return result;
}

bool CNSNpcParamsExt::ReloadNpcScript(unsigned short wNpcId) {
	std::map<unsigned long, CNSNpcParams::_NpcScript *>::iterator iter_script =
		this->m_mapNpcScript.find(wNpcId);

	if (iter_script == this->m_mapNpcScript.end()) {
		GameUtil::Output("ReloadNpcScript(%d) find failure\n", wNpcId);
		return false;
	}

	CNSNpcParams::_NpcScript insert;
	if (ReadNpcScript(wNpcId, insert) == false) {
		GameUtil::Output("ReadNpcScript(%d) failure\n", wNpcId);
		return false;
	}

    char *szScript = iter_script->second->szScript;
    iter_script->second->szScript = insert.szScript;
    delete []szScript;
    return true;
}
