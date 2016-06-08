#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "base/file_util.h"
#include "third-party/zlib-1.2.8/zlib.h"

class CNSMapManagerFilter : public CNSMapManager {
public:
    BOOL MapLoadFilter() {
        if (!this->m_btRegion) {
            return TRUE;
        }

        unsigned int dwWidth = this->m_dwWidth / this->m_wCellSize;
        unsigned int dwHeight = this->m_dwHeight / this->m_wCellSize;

        char zlib_filename[MAX_PATH];
        sprintf(zlib_filename, ".\\profile\\%s.zlib", this->m_szFileName);

        base::FileReader reader(zlib_filename);
        if (!reader.IsSuccess()) {
            LOGFATAL("can not load file:%s", zlib_filename);
            return FALSE;
        }

        unsigned long uncompress_size = dwWidth * dwHeight;
        unsigned char *uncompress_data = new unsigned char[dwWidth * dwHeight];
        if (uncompress(uncompress_data, &uncompress_size, reinterpret_cast<const Bytef *>(reader.Get()), reader.Size()) != Z_OK
            || uncompress_size != dwWidth * dwHeight) {
                delete []uncompress_data;
                LOGFATAL("can not uncompress file:%s", zlib_filename);
                return FALSE;
        }

        for (unsigned int y = 0; y < dwHeight; ++y) {
            memcpy(this->m_ppMapData[y], &uncompress_data[dwWidth * y], dwWidth);
        }

        delete []uncompress_data;
        return TRUE;
    }

};



bool CNSMapManagerFilterInit() {
    return CNSMapManager::_PatchMapLoad(&CNSMapManagerFilter::MapLoadFilter);
}