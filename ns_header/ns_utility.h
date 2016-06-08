#ifndef NSHEADER_NS_UTILITY_H_
#define NSHEADER_NS_UTILITY_H_


namespace SteamEngine { namespace Win32 { namespace Utility {
void OutputFile(char *, char *, ...);    PATCH_STATIC(void, OutputFile, char * _COMMA char * _COMMA ..., 0x415830);
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(void OutputFile(char * _COMMA char * _COMMA ...), 0x415830);
#endif

struct _Invoke {
    PATCH_STATIC_INVOKE(void, OutputFile, char * _COMMA char * _COMMA ...);
};

}}}



#endif