#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class COutputFileFilter : public COutputFile {
public:
    BOOL InitFilter() {
        return TRUE;
    }

    void SetFilenameFilter(char *szFilename) {
        if (*szFilename == '\\') {
            strcpy(szFilename, szFilename + 1);
        }

        this->m_cs.Enter();
        if (this->m_fp) {
            if (strcmp(this->m_szFilename, szFilename)) {
                this->Close();
                strcpy_s(this->m_szFilename, 0x100u, szFilename);
                this->Open();
            }
        } else {
            strcpy_s(this->m_szFilename, 0x100u, szFilename);
            this->Open();
        }
        this->m_cs.Leave();
    }
};



bool COutputFileFilterInit() {
    return COutputFile::_PatchSetFilename(&COutputFileFilter::SetFilenameFilter);
}