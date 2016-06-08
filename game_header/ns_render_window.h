#ifndef GAME_HEADER_NS_ROOT_WINDOW_H_
#define GAME_HEADER_NS_ROOT_WINDOW_H_



class NSRenderWindow : public NSWindow, public DefineInstance<NSRenderWindow, 0x712F44> {
    static const unsigned int _vtable = 0x006B1958;
    static const unsigned int _size = 0x120;
public:
    static bool _Init() {
        __CHECK_THIS_SIZE(NSRenderWindow);
        return true;
    }

    unsigned long dwordB0;
    unsigned long dwordB4;
    unsigned long dwordB8;
    unsigned long dwordBC;
    unsigned long dwordC0;
    unsigned long dwordC4;
    unsigned long dwordC8;
    unsigned long dwordCC;
    unsigned long dwordD0;
    unsigned long dwordD4;
    unsigned long dwordD8;
    unsigned char byteDC;
    unsigned char gapDD[5];
    short wordE2;
    unsigned char byteE4;
    unsigned char byteE5;
    unsigned long dwordE8;
    unsigned long dwordEC;
    unsigned long dwordF0;
    unsigned long dwordF4;
    unsigned long dwordF8;
    unsigned long dwordFC;
    unsigned long dword100;
    unsigned long dword104;
    unsigned long dword108;
    HDC phdc__10C;
    unsigned long dword110;
    unsigned long dword114;
    void *pvoid118;
    unsigned long dword11C;
};





#endif