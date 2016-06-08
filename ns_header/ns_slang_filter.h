#ifndef NSHEADER_NS_SLANG_FILTER_H_
#define NSHEADER_NS_SLANG_FILTER_H_


class CNSSlangFilter {
public:
    static const unsigned int _size = 0x13884;

    CNSSlangFilter(char *);    PATCH_MEMBER(CNSSlangFilter &, Constructor, char *, 0x4DC070);
    int IsSlang(char *);    PATCH_MEMBER(int, IsSlang, char *, 0x4DC110);
    int IsSlangEx(char *);    PATCH_MEMBER(int, IsSlangEx, char *, 0x4DC170);
    char * NoneSpace(char *, char *, int);    PATCH_MEMBER(char *, NoneSpace, char * _COMMA char * _COMMA int, 0x4DC270);
    char m_szSlangArray[1000][80];//this+0x0
    int m_nSlangCount;//this+0x13880

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSSlangFilter &, CNSSlangFilter, Constructor, char *);
PATCH_MEMBER_INVOKE(int, CNSSlangFilter, IsSlang, char *);
PATCH_MEMBER_INVOKE(int, CNSSlangFilter, IsSlangEx, char *);
PATCH_MEMBER_INVOKE(char *, CNSSlangFilter, NoneSpace, char * _COMMA char * _COMMA int);
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSSlangFilter::Constructor(char *), 0x4DC070);
//DEFINE_NAKED_JMP(int CNSSlangFilter::IsSlang(char *), 0x4DC110);
//DEFINE_NAKED_JMP(int CNSSlangFilter::IsSlangEx(char *), 0x4DC170);
//DEFINE_NAKED_JMP(char * CNSSlangFilter::NoneSpace(char * _COMMA char * _COMMA int), 0x4DC270);
#endif
};



#endif