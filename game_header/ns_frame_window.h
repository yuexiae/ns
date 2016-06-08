#ifndef GAME_HEADER_NS_FRAME_WINDOW_H_
#define GAME_HEADER_NS_FRAME_WINDOW_H_

#include "game_header/ns_type.h"

#pragma pack(push, 8)
class NSFrameWindow : public NSWindow {
    static const unsigned int _vtable = 0x006B0ED8;
    static const unsigned int _size = 0x1ec;
public:
    static bool _Init() {
        __CHECK_THIS_SIZE(NSFrameWindow);
        return base::HookUtil::PatchCtor(CLIENT_DLL_NAME, "??0NSFrameWindow@@QAE@HHFV?$NSRect@H@@HDD0D@Z", 0x004F39A0)
            && base::HookUtil::PatchDtor<NSFrameWindow>(0x004F3800);
    }

    EXPORT_NO_INLINE NSFrameWindow(int nId, int a3, short a4, NSRect<int> rect, int a9, char a10, char a11, NSRect<int> rect2, char a16) { _ASM_CC_RESERVE }

    EXPORT_NO_INLINE virtual ~NSFrameWindow() { _ASM_CC_RESERVE }
    DEFINE_VIRTUAL_NSWINDOW();
    virtual void _vptr32();
    virtual void _vptr33();
    virtual void _vptr34(int, int);
    virtual void _vptr35(int);

    unsigned long dwordB0;
    unsigned char byteB4;
    unsigned char byteB5;
    unsigned char gapB6[6];
    unsigned char byteBC;
    unsigned char gapBD[3];
    unsigned long dwordC0;
    unsigned long dwordC4;
    unsigned long dwordC8;
    unsigned long dwordCC;
    unsigned char gapD0[8];
    unsigned long dwordD8;
    unsigned long dwordDC;
    unsigned long dwordE0;
    unsigned long dwordE4;
    unsigned char byteE8;
    unsigned char byteE9;
    char charEA[0x100];
};
#pragma pack(pop)
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_NSWINDOW(NSFrameWindow);
DEFINE_NAKED_VTABLE(NSFrameWindow, void NSFrameWindow::_vptr32(), 32);
DEFINE_NAKED_VTABLE(NSFrameWindow, void NSFrameWindow::_vptr33(), 33);
DEFINE_NAKED_VTABLE(NSFrameWindow, void NSFrameWindow::_vptr34(int, int), 34);
DEFINE_NAKED_VTABLE(NSFrameWindow, void NSFrameWindow::_vptr35(int), 35);
#endif


#endif