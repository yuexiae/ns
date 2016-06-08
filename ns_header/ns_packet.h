#ifndef NSHEADER_NS_PACKET_H_
#define NSHEADER_NS_PACKET_H_

#include "base/micros.h"
#include "base/hook_util.h"
#include "base/game_packet.h"

namespace SteamEngine { namespace Win32 { namespace System {

class CPacket;

class CPacketBinder {
public:
	static const unsigned int _size = 0x2008;

	typedef base::GamePacket CPacket;

	CPacketBinder(const CPacketBinder &);
	CPacketBinder();    PATCH_MEMBER(CPacketBinder &, Constructor, , 0x410890);
	virtual ~CPacketBinder();    PATCH_MEMBER(void, Destructor, , 0x4108B0);
	int Add(char *, int);    PATCH_MEMBER(int, Add, char * _COMMA int, 0x410900);
	void Clear();    PATCH_MEMBER(void, Clear, , 0x4108D0);
	char * GetBuffer();    PATCH_MEMBER(char *, GetBuffer, , 0x4B4930);
	unsigned long GetLength();    PATCH_MEMBER(unsigned long, GetLength, , 0x4B4950);
	char m_cPacketBuffer[0x2000];//this+0x4
	unsigned long m_dwLen;//this+0x2004
	CPacketBinder & operator=(const CPacketBinder &);
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CPacketBinder &, CPacketBinder, Constructor, );
	PATCH_MEMBER_INVOKE(void, CPacketBinder, Destructor, );
	PATCH_MEMBER_INVOKE(int, CPacketBinder, Add, char * _COMMA int);
	PATCH_MEMBER_INVOKE(void, CPacketBinder, Clear, );
	PATCH_MEMBER_INVOKE(char *, CPacketBinder, GetBuffer, );
	PATCH_MEMBER_INVOKE(unsigned long, CPacketBinder, GetLength, );
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CPacketBinder::Constructor(), 0x410890);
	//DEFINE_NAKED_JMP(CPacketBinder::Destructor(), 0x4108B0);
	DEFINE_NAKED_JMP(int CPacketBinder::Add(char * _COMMA int), 0x410900);
	DEFINE_NAKED_JMP(void CPacketBinder::Clear(), 0x4108D0);
	DEFINE_NAKED_JMP(char * CPacketBinder::GetBuffer(), 0x4B4930);
	DEFINE_NAKED_JMP(unsigned long CPacketBinder::GetLength(), 0x4B4950);
#endif

class CPacketEncipher {
public:
	static const unsigned int _size = 0x4;

	typedef base::GamePacket CPacket;

	CPacketEncipher(const CPacketEncipher &);
	CPacketEncipher();    PATCH_MEMBER(CPacketEncipher &, Constructor, , 0x410990);
	virtual ~CPacketEncipher();    PATCH_MEMBER(void, Destructor, , 0x4109B0);
	static void Init();    PATCH_STATIC(void, Init, , 0x4109D0);
	int Encode(unsigned char *, int, unsigned char *, int &);    PATCH_MEMBER(int, Encode, unsigned char * _COMMA int _COMMA unsigned char * _COMMA int &, 0x410EC0);
	int Encode(CPacket &);    PATCH_MEMBER(int, Encode, CPacket &, 0x410B30);
	int Decode(unsigned char *, int, unsigned char *);    PATCH_MEMBER(int, Decode, unsigned char * _COMMA int _COMMA unsigned char *, 0x411010);
	int Decode(CPacket &);    PATCH_MEMBER(int, Decode, CPacket &, 0x410D00);
	static unsigned char m_arrayKey[0x100];//[0x55B0D0]  [0015B0D0:0003:0003B0D0]
	CPacketEncipher & operator=(const CPacketEncipher &);
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CPacketEncipher &, CPacketEncipher, Constructor, );
	PATCH_MEMBER_INVOKE(void, CPacketEncipher, Destructor, );
	PATCH_STATIC_INVOKE(void, Init, );
	PATCH_MEMBER_INVOKE(int, CPacketEncipher, Encode, unsigned char * _COMMA int _COMMA unsigned char * _COMMA int &);
	PATCH_MEMBER_INVOKE(int, CPacketEncipher, Encode, CPacket &);
	PATCH_MEMBER_INVOKE(int, CPacketEncipher, Decode, unsigned char * _COMMA int _COMMA unsigned char *);
	PATCH_MEMBER_INVOKE(int, CPacketEncipher, Decode, CPacket &);
	};*/

	DEFINE_STATIC_MEMBER(CPacketEncipher *, g_Encipher, 0x55A1B0); //class CPacketEncipher g_Encipher;//[0x55A1B0]  [0015A1B0:0003:0003A1B0]
};

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CPacketEncipher::Constructor(), 0x410990);
	//DEFINE_NAKED_JMP(CPacketEncipher::Destructor(), 0x4109B0);
	//DEFINE_NAKED_JMP(void CPacketEncipher::Init(), 0x4109D0);
	//DEFINE_NAKED_JMP(int CPacketEncipher::Encode(unsigned char * _COMMA int _COMMA unsigned char * _COMMA int &), 0x410EC0);
	DEFINE_NAKED_JMP(int CPacketEncipher::Encode(CPacket &), 0x410B30);
	//DEFINE_NAKED_JMP(int CPacketEncipher::Decode(unsigned char * _COMMA int _COMMA unsigned char *), 0x411010);
	DEFINE_NAKED_JMP(int CPacketEncipher::Decode(CPacket &), 0x410D00);
#endif


class CPacket {
public:
	static const unsigned int _size = 0x201c;

	CPacket(const CPacket &);    PATCH_MEMBER(CPacket &, Constructor, const CPacket &, 0x40B200);
	CPacket(unsigned short);
	CPacket();    PATCH_MEMBER(CPacket &, Constructor, , 0x402870);
	int IsValidHeader();    PATCH_MEMBER(int, IsValidHeader, , 0x40AFB0);
	int IsValidPacket();    PATCH_MEMBER(int, IsValidPacket, , 0x40AF60);
	CPacket & SetId(unsigned short);    PATCH_MEMBER(CPacket &, SetId, unsigned short, 0x4028C0);
	unsigned short GetId();    PATCH_MEMBER(unsigned short, GetId, , 0x4028E0);
	unsigned short GetDataSize();    PATCH_MEMBER(unsigned short, GetDataSize, , 0x402750);
	int GetPacketSize();    PATCH_MEMBER(int, GetPacketSize, , 0x402710);
	int GetReceivedSize();
	void ResetPos();
	void Clear(int);    PATCH_MEMBER(void, Clear, int, 0x4027E0);
	char * GetPacketBuffer();    PATCH_MEMBER(char *, GetPacketBuffer, , 0x402730);
	char * GetDataBuffer();    PATCH_MEMBER(char *, GetDataBuffer, , 0x411130);
	void CopyToBuffer(char *, int);    PATCH_MEMBER(void, CopyToBuffer, char * _COMMA int, 0x402770);
	CPacket & operator=(CPacket &);    //PATCH_MEMBER(CPacket &, operator=, CPacket &, 0x40B3C0);
	CPacket & operator<<(CPacket &);
	CPacket & operator<<(char *);    //PATCH_MEMBER(CPacket &, operator<<, char *, 0x419F70);
	CPacket & operator<<(int);    //PATCH_MEMBER(CPacket &, operator<<, int, 0x419FA0);
	CPacket & operator<<(unsigned long);    //PATCH_MEMBER(CPacket &, operator<<, unsigned long, 0x419FA0);
	CPacket & operator<<(unsigned short);    //PATCH_MEMBER(CPacket &, operator<<, unsigned short, 0x411150);
	CPacket & operator<<(unsigned char);    //PATCH_MEMBER(CPacket &, operator<<, unsigned char, 0x402900);
	CPacket & operator>>(CPacket &);
	CPacket & operator>>(char *);    PATCH_MEMBER(CPacket &, ReadString, char *, 0x4C7E70);
	CPacket & operator>>(int &);    //PATCH_MEMBER(CPacket &, operator>>, int &, 0x4C9430);
	CPacket & operator>>(unsigned long &);    //PATCH_MEMBER(CPacket &, operator>>, unsigned long &, 0x4C9430);
	CPacket & operator>>(unsigned short &);    //PATCH_MEMBER(CPacket &, operator>>, unsigned short &, 0x411170);
	CPacket & operator>>(unsigned char &);    //PATCH_MEMBER(CPacket &, operator>>, unsigned char &, 0x402A90);
	void ReadData(void *, int);    PATCH_MEMBER(void, ReadData, void * _COMMA int, 0x402AB0);
	void WriteData(void *, int);    PATCH_MEMBER(void, WriteData, void * _COMMA int, 0x402920);
	int IsReadEnd();
	struct HEADER {
		static const unsigned int _size = 0x8;

		unsigned short * nDataSize;//this+0x0
		unsigned short * nProtocolId;//this+0x4
	};

	struct CPacket::HEADER m_packetHeader;//this+0x0
	char m_cPacketBuffer[0x2000];//this+0x8
	char * m_cDataBuffer;//this+0x2008
	int m_nReadPos;//this+0x200C
	int m_nWritePos;//this+0x2010
	int m_nEndPos;//this+0x2014
	int m_nReceivedSize;//this+0x2018

	struct _Invoke {
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, Constructor, const CPacket &);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, Constructor2, );
		//PATCH_MEMBER_INVOKE(int, CPacket, IsValidHeader, );
		//PATCH_MEMBER_INVOKE(int, CPacket, IsValidPacket, );
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, SetId, unsigned short);
		//PATCH_MEMBER_INVOKE(unsigned short, CPacket, GetId, );
		//PATCH_MEMBER_INVOKE(unsigned short, CPacket, GetDataSize, );
		//PATCH_MEMBER_INVOKE(int, CPacket, GetPacketSize, );
		//PATCH_MEMBER_INVOKE(void, CPacket, Clear, int);
		//PATCH_MEMBER_INVOKE(char *, CPacket, GetPacketBuffer, );
		//PATCH_MEMBER_INVOKE(char *, CPacket, GetDataBuffer, );
		//PATCH_MEMBER_INVOKE(void, CPacket, CopyToBuffer, char * _COMMA int);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator=, CPacket &);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator<<, char *);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator<<, int);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator<<, unsigned long);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator<<, unsigned short);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator<<, unsigned char);
		PATCH_MEMBER_INVOKE(CPacket &, CPacket, ReadString, char *);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator>>, int &);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator>>, unsigned long &);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator>>, unsigned short &);
		//PATCH_MEMBER_INVOKE(CPacket &, CPacket, operator>>, unsigned char &);
		//PATCH_MEMBER_INVOKE(void, CPacket, ReadData, void * _COMMA int);
		//PATCH_MEMBER_INVOKE(void, CPacket, WriteData, void * _COMMA int);
	};
};


#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CPacket::Constructor(const CPacket &), 0x40B200);
	//DEFINE_NAKED_JMP(CPacket::Constructor(), 0x402870);
	//DEFINE_NAKED_JMP(int CPacket::IsValidHeader(), 0x40AFB0);
	//DEFINE_NAKED_JMP(int CPacket::IsValidPacket(), 0x40AF60);
	DEFINE_NAKED_JMP(CPacket & CPacket::SetId(unsigned short), 0x4028C0);
	DEFINE_NAKED_JMP(unsigned short CPacket::GetId(), 0x4028E0);
	//DEFINE_NAKED_JMP(unsigned short CPacket::GetDataSize(), 0x402750);
	DEFINE_NAKED_JMP(int CPacket::GetPacketSize(), 0x402710);
	//DEFINE_NAKED_JMP(void CPacket::Clear(int), 0x4027E0);
	//DEFINE_NAKED_JMP(char * CPacket::GetPacketBuffer(), 0x402730);
	//DEFINE_NAKED_JMP(char * CPacket::GetDataBuffer(), 0x411130);
	//DEFINE_NAKED_JMP(void CPacket::CopyToBuffer(char * _COMMA int), 0x402770);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator=(CPacket &), 0x40B3C0);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator<<(char *), 0x419F70);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator<<(int), 0x419FA0);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator<<(unsigned long), 0x419FA0);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator<<(unsigned short), 0x411150);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator<<(unsigned char), 0x402900);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator>>(char *), 0x4C7E70);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator>>(int &), 0x4C9430);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator>>(unsigned long &), 0x4C9430);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator>>(unsigned short &), 0x411170);
	//DEFINE_NAKED_JMP(CPacket & CPacket::operator>>(unsigned char &), 0x402A90);
	DEFINE_NAKED_JMP(void CPacket::ReadData(void * _COMMA int), 0x402AB0);
	DEFINE_NAKED_JMP(void CPacket::WriteData(void * _COMMA int), 0x402920);
#endif

}}}//namespace SteamEngine { namespace Win32 { namespace System {

typedef SteamEngine::Win32::System::CPacketBinder CPacketBinder;
typedef SteamEngine::Win32::System::CPacketEncipher CPacketEncipher;
typedef base::GamePacket CPacket;


#endif