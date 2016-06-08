#ifndef GAME_HEADER_NS_WINDOW_H_
#define GAME_HEADER_NS_WINDOW_H_

#include "game_header/ns_type.h"


#pragma pack(push, 8)
class NSWindow {
    static const unsigned int _vtable = 0x006B0E58;
    static const unsigned int _size = 0xb0;
public:

    static bool _Init() {
        __CHECK_THIS_SIZE(NSWindow);
        __CHECK_STRUCT_OFFSET(NSWindow, m_btCount, 0x04);
        __CHECK_STRUCT_OFFSET(NSWindow, m_Rect, 0x08);
        __CHECK_STRUCT_OFFSET(NSWindow, m_bVisible, 0x20);
        __CHECK_STRUCT_OFFSET(NSWindow, m_bLeftPressed, 0x24);
        __CHECK_STRUCT_OFFSET(NSWindow, m_bRightPressed, 0x25);
        __CHECK_STRUCT_OFFSET(NSWindow, m_Rect2, 0x50);
        __CHECK_STRUCT_OFFSET(NSWindow, m_Childs, 0x60);
        __CHECK_STRUCT_OFFSET(NSWindow, m_Texture, 0x6c);
        __CHECK_STRUCT_OFFSET(NSWindow, m_Parent, 0x70);
        __CHECK_STRUCT_OFFSET(NSWindow, m_btType, 0x74);
        __CHECK_STRUCT_OFFSET(NSWindow, m_dwId, 0x78);
        __CHECK_STRUCT_OFFSET(NSWindow, m_bModal, 0x7c);

        return base::HookUtil::PatchDtor<NSWindow>(0x004F2E60);
    }

    EXPORT_NO_INLINE NSWindow() { _ASM_CC_RESERVE }

    EXPORT_NO_INLINE virtual ~NSWindow() { _ASM_CC_RESERVE }
#define DEFINE_VIRTUAL_NSWINDOW()\
    virtual void Destory();\
    virtual void Draw();\
    virtual void _vptr3();\
    virtual void _vptr4();\
    virtual void SetModal(bool);\
    virtual void DisableModal();\
    virtual void OppositeModal();\
    virtual void OnVisible();\
    virtual void OnInvisible();\
    virtual void _vptr10();\
    virtual void _vptr11();\
    virtual void _vptr12();\
    virtual void SetVisible(bool bVisible);\
    virtual void SetInvisible();\
    virtual void _vptr15();\
    virtual void _vptr16();\
    virtual void _vptr17();\
    virtual void AddChild(NSWindow *, NSRect<int>);\
    virtual void OnEvent(unsigned int&, int, int);\
    virtual void _vptr20(int, int);\
    virtual void _vptr21(int);\
    virtual void _vptr22();\
    virtual void _vptr23(int, int);\
    virtual void _vptr24(int, short);\
    virtual void _vptr25(int, short);\
    virtual void _vptr26(int, short);\
    virtual void _vptr27(int, short);\
    virtual bool _vptr28(int, int);\
    virtual bool _vptr29(int);\
    virtual bool _vptr30();\
    virtual void _vptr31();
    DEFINE_VIRTUAL_NSWINDOW();

    unsigned char m_btCount;
    unsigned char gap5[3];
    NSRect<int> m_Rect;
    unsigned long dword18;
    unsigned long dword1C;
    bool m_bVisible;
    unsigned char byte21;
    unsigned char byte22;
    unsigned char byte23;
    bool m_bLeftPressed;
    bool m_bRightPressed;
    unsigned char byte26;
    unsigned long dword28;
    unsigned long dword2C;
    unsigned char byte30;
    unsigned char gap31[19];
    unsigned long dword44;
    unsigned long dword48;
    unsigned long dword4C;
    NSRect<int> m_Rect2;
    unsigned long m_Childs;
    unsigned long dword64;
    unsigned long dword68;
    unsigned long m_Texture;
    NSWindow *m_Parent;
    unsigned char m_btType;
    unsigned char gap75[3];
    unsigned long m_dwId;
    bool m_bModal;
    unsigned char byte7D;
    unsigned char byte7E;
    unsigned char gap7F[13];
    unsigned long dword8C;
    unsigned char gap90[2];
    short word92;
    unsigned char byte94;
    unsigned char gap95[3];
    float dword98;
    unsigned char byte9C;
    unsigned char gap9D[3];
    unsigned long dwordA0;
    unsigned char byteA4;
    unsigned char gapA5[3];
    unsigned long dwordA8;
    short wordAC;
};
#pragma pack(pop)



#ifdef DEFINE_NS_CPP
#define DEFINE_NAKED_NSWINDOW(name) \
DEFINE_NAKED_VTABLE(name, void name::Destory(), 1);\
DEFINE_NAKED_VTABLE(name, void name::Draw(),    2);\
DEFINE_NAKED_VTABLE(name, void name::_vptr3(),  3);\
DEFINE_NAKED_VTABLE(name, void name::_vptr4(),  4);\
DEFINE_NAKED_VTABLE(name, void name::SetModal(bool),  5);\
DEFINE_NAKED_VTABLE(name, void name::DisableModal(),  6);\
DEFINE_NAKED_VTABLE(name, void name::OppositeModal(),  7);\
DEFINE_NAKED_VTABLE(name, void name::OnVisible(),  8);\
DEFINE_NAKED_VTABLE(name, void name::OnInvisible(),  9);\
DEFINE_NAKED_VTABLE(name, void name::_vptr10(), 10);\
DEFINE_NAKED_VTABLE(name, void name::_vptr11(), 11);\
DEFINE_NAKED_VTABLE(name, void name::_vptr12(), 12);\
DEFINE_NAKED_VTABLE(name, void name::SetVisible(bool), 13);\
DEFINE_NAKED_VTABLE(name, void name::SetInvisible(), 14);\
DEFINE_NAKED_VTABLE(name, void name::_vptr15(), 15);\
DEFINE_NAKED_VTABLE(name, void name::_vptr16(), 16);\
DEFINE_NAKED_VTABLE(name, void name::_vptr17(), 17);\
DEFINE_NAKED_VTABLE(name, void name::AddChild(NSWindow *, NSRect<int>), 18);\
DEFINE_NAKED_VTABLE(name, void name::OnEvent(unsigned int&, int, int), 19);\
DEFINE_NAKED_VTABLE(name, void name::_vptr20(int, int), 20);\
DEFINE_NAKED_VTABLE(name, void name::_vptr21(int), 21);\
DEFINE_NAKED_VTABLE(name, void name::_vptr22(), 22);\
DEFINE_NAKED_VTABLE(name, void name::_vptr23(int, int), 23);\
DEFINE_NAKED_VTABLE(name, void name::_vptr24(int, short), 24);\
DEFINE_NAKED_VTABLE(name, void name::_vptr25(int, short), 25);\
DEFINE_NAKED_VTABLE(name, void name::_vptr26(int, short), 26);\
DEFINE_NAKED_VTABLE(name, void name::_vptr27(int, short), 27);\
DEFINE_NAKED_VTABLE(name, bool name::_vptr28(int, int), 28);\
DEFINE_NAKED_VTABLE(name, bool name::_vptr29(int), 29);\
DEFINE_NAKED_VTABLE(name, bool name::_vptr30(), 30);\
DEFINE_NAKED_VTABLE(name, void name::_vptr31(), 31);
DEFINE_NAKED_NSWINDOW(NSWindow);
#endif


#endif