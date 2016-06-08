#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


        
class NSUtilityFilter {
public:
    static SteamEngine::Win32::Utility::_Invoke invoke_;

    static void OutputFileFilter(char *szFilename, char *szFmt, ...) {
        if (*szFilename == '\\') {
            strcpy(szFilename, szFilename + 1);
        }

        va_list ap;
        va_start(ap, szFmt);

        SYSTEMTIME st;
        GetLocalTime(&st);

        /*
        FILE *fp = fopen(szFilename, "rt");
        if (fp) {
            bLarge = 0;
            fseek(fp, 0, SEEK_END);
            if (ftell(fp) > 1024 * 1000) {
                bLarge = 1;
            }

            fclose(fp);

            if (bLarge == 1){
                char szTemp[1024];
                sprintf(szTemp, "%s.%02d%02d%02d%02d", szFilename, st.wYear % 100, st.wMonth, st.wDay, st.wHour);
                rename(szFilename, szTemp);
            }
        }*/

        FILE *fp = _fsopen(szFilename, "a+t", 32);
        if (fp) {
            fprintf(
                fp,
                "%02d/%02d/%02d %02d:%02d:%02d:%03d ",
                st.wYear % 100,
                st.wMonth,
                st.wDay,
                st.wHour,
                st.wMinute,
                st.wSecond,
                st.wMilliseconds);

            vfprintf(fp, szFmt, ap);

            fclose(fp);
        }

        va_end(ap);
    }
};


SteamEngine::Win32::Utility::_Invoke NSUtilityFilter::invoke_;

bool NSUtilityFilterInit() {
    return SteamEngine::Win32::Utility::_PatchOutputFile(&NSUtilityFilter::OutputFileFilter, &NSUtilityFilter::invoke_.OutputFile);
}