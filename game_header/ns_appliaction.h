#ifndef GAME_HEADER_NS_APPLICATION_H_
#define GAME_HEADER_NS_APPLICATION_H_



class NSApplication : public DefineInstance<NSApplication, 0x00712F30> {
    static const unsigned int _vtable = 0x6A66F8;
    static const unsigned int _size = 0x3AC;
public:
    static bool _Init() {
        __CHECK_THIS_SIZE(NSApplication);
        __CHECK_STRUCT_OFFSET(NSApplication, m_Hwnd, 0x04);
        __CHECK_STRUCT_OFFSET(NSApplication, m_dwFrameRate, 0x84);
        return true;
    }

  unsigned long vtable;
  HWND m_Hwnd;
  unsigned long dword8;
  unsigned long dwordC;
  unsigned long dword10;
  unsigned long dword14;
  unsigned long dword18;
  unsigned long dword1C;
  unsigned long dword20;
  unsigned long dword24;
  unsigned long dword28;
  unsigned long dword2C;
  unsigned long dword30;
  unsigned long dword34;
  unsigned long dword38;
  unsigned long dword3C;
  unsigned char byte40;
  unsigned char byte41;
  unsigned char byte42;
  unsigned long dword44;
  unsigned long dword48;
  unsigned long dword4C;
  unsigned long dword50;
  unsigned long dword54;
  unsigned long dword58;
  unsigned long dword5C;
  unsigned long dword60;
  unsigned long dword64;
  unsigned long dword68;
  unsigned long dword6C;
  unsigned long dword70;
  unsigned long dword74;
  unsigned long dword78;
  unsigned long dword7C;
  unsigned long dword80;
  unsigned long m_dwFrameRate;
  unsigned long dword88;
  unsigned long dword8C;
  unsigned long dword90;
  unsigned char byte94;
  unsigned char gap95[159];
  unsigned char byte134;
  unsigned char byte135;
  int dnamenode138;
  unsigned char gap13C[4];
  unsigned long dword140;
  unsigned long dword144;
  unsigned long dword148;
  unsigned long dword14C;
  unsigned long dword150;
  unsigned long dword154;
  unsigned char byte158;
  unsigned char byte159;
  unsigned char byte15A;
  unsigned char byte15B;
  unsigned long dword15C;
  unsigned char gap160[540];
  unsigned char byte37C;
  unsigned long dword380;
  unsigned long dword384;
  struct _RTL_CRITICAL_SECTION rtl_critical_section388;
  unsigned char gap3A0[8];
  unsigned long dword3A8;
};






#endif