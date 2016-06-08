#ifndef NSHEADER_NS_RAND32_H_
#define NSHEADER_NS_RAND32_H_

class CRand32 {
public:
    static const unsigned int _size = 0x9c4;

    CRand32();    PATCH_MEMBER(CRand32 &, Constructor, , 0x411190);
    void Init(unsigned long);    PATCH_MEMBER(void, Init, unsigned long, 0x4111C0);
    unsigned long GetRand32();    PATCH_MEMBER(unsigned long, GetRand32, , 0x411230);
    unsigned long m_mt[0x270];//this+0x0
    int m_mti;//this+0x9C0

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CRand32 &, CRand32, Constructor, );
PATCH_MEMBER_INVOKE(void, CRand32, Init, unsigned long);
PATCH_MEMBER_INVOKE(unsigned long, CRand32, GetRand32, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CRand32::Constructor(), 0x411190);
//DEFINE_NAKED_JMP(void CRand32::Init(unsigned long), 0x4111C0);
//DEFINE_NAKED_JMP(unsigned long CRand32::GetRand32(), 0x411230);
#endif
};




#endif