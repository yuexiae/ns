#ifndef NSHEADER_NS_GLOBAL_H_
#define NSHEADER_NS_GLOBAL_H_


namespace NS {

void SafeValue(unsigned long &, float);    PATCH_STATIC(void, SafeValue, unsigned long & _COMMA float, 0x4DCF50);
void SafeValue(unsigned short &, float);    PATCH_STATIC(void, SafeValue, unsigned short & _COMMA float, 0x4DCF00);
void SafeValue(unsigned char &, float);    PATCH_STATIC(void, SafeValue, unsigned char & _COMMA float, 0x4DCEB0);
void SafeValue(unsigned long &, int);    PATCH_STATIC(void, SafeValue, unsigned long & _COMMA int, 0x4DCE90);
void SafeValue(unsigned short &, int);    PATCH_STATIC(void, SafeValue, unsigned short & _COMMA int, 0x4DCE50);
void SafeValue(unsigned char &, int);    PATCH_STATIC(void, SafeValue, unsigned char & _COMMA int, 0x4DCE20);


#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(void SafeValue(unsigned long & _COMMA float), 0x4DCF50);
DEFINE_NAKED_JMP(void SafeValue(unsigned short & _COMMA float), 0x4DCF00);
DEFINE_NAKED_JMP(void SafeValue(unsigned char & _COMMA float), 0x4DCEB0);
DEFINE_NAKED_JMP(void SafeValue(unsigned long & _COMMA int), 0x4DCE90);
DEFINE_NAKED_JMP(void SafeValue(unsigned short & _COMMA int), 0x4DCE50);
DEFINE_NAKED_JMP(void SafeValue(unsigned char & _COMMA int), 0x4DCE20);
#endif
}





#endif