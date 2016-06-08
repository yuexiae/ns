#include "server/server_pch.h"

#include "ns_header/ns.h"



class CPacketFilter : public SteamEngine::Win32::System::CPacket {
public:
	static CPacket::_Invoke invoke_;
};

SteamEngine::Win32::System::CPacket::_Invoke CPacketFilter::invoke_;

bool CPacketFilterInit() {
    return true;
}
