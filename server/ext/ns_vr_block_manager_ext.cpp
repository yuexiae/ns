#include "server/server_pch.h"

#include "server/ext/ns_vr_block_manager_ext.h"
#include "server/ext/ns_pc_ext.h"
#include "server/ext/ns_npc_ext.h"

BOOL CNSVrBlockManagerExt::BroadcastPcNew(CNSCharacter *pChar, CPacket& packet, CNSPc *pTarget, _NSRANGE& range, int bSendExcept, bool& bEncode) {
    __try {
        if (pTarget == NULL) {
            GameUtil::Output("Exception: NSVrBlockPc::BroadcastPc(Owner: %08x | This: NULL | Pos: %d/%d - %d/%d)\n", pChar->m_dwObjectId, range.x1, range.y1, range.x2, range.y2);
            return FALSE;
        }

        if (IsBadReadPtr(pTarget, sizeof(CNSPcExt)) == 1 ) {
            GameUtil::Output("Exception: NSVrBlockPc::BroadcastPc(Owner: %08x | This: %08x | Pos: %d/%d - %d/%d) - IsBadReadPtr()\n",
                pChar->m_dwObjectId, this, range.x1, range.y1, range.x2, range.y2);
            return FALSE;
        }

        if (!pTarget->IsPcClass()) {
            GameUtil::Output("Exception: NSVrBlockPc::BroadcastPc(Owner: %08x | This: %08x | Pos: %d/%d - %d/%d) - IsNotPcClass()\n",
                pChar->m_dwObjectId, this, range.x1, range.y1, range.x2, range.y2);
            return FALSE;
        }

        pTarget->IncRefCount();
        if (pTarget->m_cell.x >= range.x1 && pTarget->m_cell.x <= range.x2 && pTarget->m_cell.y >= range.y1 && pTarget->m_cell.y <= range.y2
            && (!bSendExcept || pChar->m_dwObjectId != pTarget->m_dwObjectId)) {

                bool bIsSend = false;
                switch (packet.GetId()) {
                case CNSMessageId::CSNpcEnter:
                    if (packet.GetDataSize() == 0) {
                        if (pChar->IsNpcClass()) {
                            static_cast<CNSNpc *>(pChar)->PacketEnterMessage(packet);
                        } else {
                            break;
                        }
                    }
                    
                    if (!pChar->IsClarity(pTarget) || pChar->m_dwObjectId == pTarget->m_dwObjectId) {
                        bIsSend = true;
                    }
                    break;
                case CNSMessageId::CSMove:
                    if (packet.GetDataSize() == 0) {
                        if (pChar->IsNpcClass()) {
                            static_cast<CNSNpcExt *>(pChar)->PacketMoveMessage(packet);
                        } else {
                            break;
                        }
                    }
                    
                    if (!pChar->IsClarity(pTarget) || pChar->m_dwObjectId == pTarget->m_dwObjectId) {
                        bIsSend = true;
                    }
                    break;
                case CNSMessageId::CSPcEnter:
                    if (!pChar->IsClarity(pTarget) || pChar->m_dwObjectId == pTarget->m_dwObjectId) {
                        bIsSend = true;
                    }
                    break;
                case CNSMessageId::CSText:
                    if (pChar->CheckFriendly(pTarget) || pChar->GetType() == CNSObject::ObjectType_Mob) {
                        bIsSend = true;
                    } else {
                        //send @#$@$^#@#!@@!%@#
                    }
                    break;
                default:
                    bIsSend = true;
                    break;
                }

                if (bIsSend) {
                    if (!bEncode) {
                        CPacketEncipher::g_Encipher()->Encode(packet);
                        bEncode = true;
                    }

                    pTarget->SendMessageA(packet, 0);
                }

        }
        pTarget->DecRefCount();

        return TRUE;
    } __except (CMiniDumper::WriteMiniDump(GetExceptionInformation())) {
        GameUtil::Output("Exception: NSVrBlockPc::BroadcastPc(Owner: %08x | This: %08x | Pos: %d/%d - %d/%d Dump)\n",
                pChar->m_dwObjectId, this, range.x1, range.y1, range.x2, range.y2);
    }

    return FALSE;
}

