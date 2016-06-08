#ifndef SERVER_EXT_NS_GUILD_EXT_H_
#define SERVER_EXT_NS_GUILD_EXT_H_

#include "ns_header/ns.h"

namespace internal {
class CNSGuildExtImpl {
public:
    CNSGuildExtImpl() : dummy("test") {
    }

    std::string dummy;
};
}

class CNSGuildExt : public CNSGuild, public internal::CNSGuildExtImpl {
public:
    static void LoadGuildBase();

	static CNSGuildExt* New(int nDbSeq, CNSGuild::GuildInfo &guildInfo) {
        return reinterpret_cast<CNSGuildExt *>(&reinterpret_cast<CNSGuild *>(new char[sizeof(CNSGuildExt)])->Constructor(nDbSeq, guildInfo));
	}

    struct BaseCell {
		NSPOINT2 enter;
		NSPOINT2 npc;
		NSPOINT2 mob;
	};
    static bool GetGuildBaseCell(unsigned char btRegion, int nRank, BaseCell& cell);
};









#endif