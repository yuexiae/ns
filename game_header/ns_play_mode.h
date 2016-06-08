#ifndef GAME_HEADER_NS_PALY_MODE_
#define GAME_HEADER_NS_PALY_MODE_

class CPlayMode {
    static const unsigned int _vtable = 0x006A6580;
    static const unsigned int _size = 0x20;
public:
    static bool _Init() {
        __CHECK_THIS_SIZE(CPlayMode);
        return true;
    }

	virtual ~CPlayMode();
	virtual bool Action();
	virtual void MessageProc(HWND hwnd, UINT Msg, WPARAM hdc, LPARAM lParam);
	virtual void PacketProcess(CPacket &);
	virtual void RefreshCursor();
    //...

public:
	unsigned long dword4;
	unsigned long dword8;
	float dwordC;
	unsigned long dword10;
	unsigned long dword14;
	unsigned long dword18;
	unsigned long dword1C;
};

class CPlayModeMain : public CPlayMode, public DefineInstance<CPlayModeMain, 0x00722358> {
    static const unsigned int _vtable = 0x006A9A48;
    static const unsigned int _size = 0x2C;
public:
    static bool _Init() {
        __CHECK_THIS_SIZE(CPlayModeMain);
        __CHECK_STRUCT_OFFSET(CPlayModeMain, m_wMode, 0x20);
        __CHECK_STRUCT_OFFSET(CPlayModeMain, m_wNextMode, 0x22);
        __CHECK_STRUCT_OFFSET(CPlayModeMain, m_PlayMode, 0x24);
        __CHECK_STRUCT_OFFSET(CPlayModeMain, m_dwCheckTime, 0x28);
        return true;
    }

    virtual bool Action(); PATCH_MEMBER(bool, Action, , 0x00467B10);

    unsigned short m_wMode;
    unsigned short m_wNextMode;
    unsigned long m_PlayMode;
    unsigned long m_dwCheckTime;

    struct _Invoke {
        PATCH_MEMBER_INVOKE(bool, CPlayModeMain, Action, );
    };
};

class CPlayModeLogin : public CPlayMode {
    static const unsigned int _vtable = 0x006A8D28;
    static const unsigned int _size = 0xa4;
public:
	static bool _Init() {
		__CHECK_THIS_SIZE(CPlayModeLogin);
        return true;
	}

private:
    struct v2 {
        unsigned long dword0;
        unsigned long dword4;
        unsigned long dword8;
        unsigned long dwordC;
    };

    unsigned long dword20;
    unsigned long dword24;
    unsigned long dword28;
    unsigned long dword2C;
    short word30;
    unsigned long dword34;
    unsigned char byte38;
    unsigned char byte39;
    unsigned char gap3A[66];
    unsigned long dword7C;
    unsigned long dword80;
    unsigned char byte84;
    unsigned long dword88;
    unsigned char byte8C;
    unsigned char byte8D;
    unsigned char byte8E;
    unsigned long dword90;
    v2 v94;
};


#endif