#ifndef GAME_HEADER_NS_H_
#define GAME_HEADER_NS_H_

#pragma pack(show)

#include "base/game_packet.h"
typedef base::GamePacket CPacket;

#include "game_header/ns_type.h"
#include "game_header/ns_window.h"
#include "game_header/ns_frame_window.h"
#include "game_header/ns_render_window.h"
#include "game_header/ns_play_mode.h"
#include "game_header/ns_appliaction.h"

class GameStructCheck {
public:
    static void Check() {
#define __INIT(class) class::_Init() ? LOGINFO("%s init", #class) : LOGERROR("%s init failure", #class)

        __CHECK_THIS_SIZE(base::GamePacket);

        __INIT(NSWindow);
        __INIT(NSFrameWindow);
        __INIT(NSRenderWindow);
        __INIT(CPlayMode);
        __INIT(CPlayModeMain);
        __INIT(CPlayModeLogin);
        __INIT(NSApplication);
    }

#undef __INIT
};


#endif