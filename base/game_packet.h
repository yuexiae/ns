#ifndef BASE_CPACKET_H_
#define BASE_CPACKET_H_

#include "base/logging.h"


namespace SteamEngine { namespace Win32 { namespace System {
class CException {
public:
    static const unsigned int _size = 0x404;
    
	CException(const CException &__that) {
		memcpy(this->m_szWhere, __that.m_szWhere, sizeof(this->m_szWhere));
		memcpy(this->m_szMessage, __that.m_szMessage, sizeof(this->m_szMessage));
	}

	CException(const char *szWhere, const char *szMessage) {
		strcpy_s(this->m_szWhere, 0x200u, szWhere);
		strcpy_s(this->m_szMessage, 0x200u, szMessage);
	}

	virtual ~CException() {
	}

	virtual char * GetWhere() { return this->m_szWhere; }

	virtual char * GetMessageA() { return this->m_szMessage; }

	void MessageBoxA(HWND__ *hWnd) {
		::MessageBoxA(hWnd, this->GetMessageA(), this->GetWhere(), 0x10u);
	}

    char m_szWhere[0x200];//this+0x4
    char m_szMessage[0x200];//this+0x204

	CException & operator=(const CException &);
};
}}} //namespace SteamEngine { namespace Win32 { namespace System {

typedef SteamEngine::Win32::System::CException CException;

namespace base {

class GamePacket {
public:
	static const unsigned int _size = 0x201c;

	GamePacket(const GamePacket &source) {
		this->m_cDataBuffer = 0;
		this->m_nReadPos = 0;
		this->m_nWritePos = 0;
		this->m_nReceivedSize = 0;
		this->Clear(0x2000);

		memcpy(this->m_cPacketBuffer, source.m_cPacketBuffer, 0x2000u);
		this->m_nReceivedSize = source.m_nReceivedSize;
		this->m_nReadPos = source.m_nReadPos;
		this->m_nWritePos = source.m_nWritePos;
	}

	GamePacket(unsigned short wId) {
		this->m_cDataBuffer = 0;
		this->m_nReadPos = 0;
		this->m_nWritePos = 0;
		this->m_nReceivedSize = 0;
		this->Clear(0x2000);

		SetId(wId);
	}

	GamePacket() {
		this->m_cDataBuffer = 0;
		this->m_nReadPos = 0;
		this->m_nWritePos = 0;
		this->m_nReceivedSize = 0;
		this->Clear(0x2000);
	}

	int IsValidHeader();
	int IsValidPacket();

	GamePacket & SetId(unsigned short wId) {
		*this->m_packetHeader.nProtocolId = wId;
		return *this;
	}

	unsigned short GetId() {
		return *this->m_packetHeader.nProtocolId;
	}

	unsigned short GetDataSize() {
		return *this->m_packetHeader.nDataSize;
	}

	int GetPacketSize() {
		return this->GetDataSize() + 4;
	}

	int GetReceivedSize();

	void ResetPos() {
		this->m_nReadPos = 0;
	}

	void Clear(int bufferSize) {
		if (bufferSize > 0x2000) {
			bufferSize = 0x2000;
		} 

		memset(this->m_cPacketBuffer, 0, bufferSize);
		this->m_packetHeader.nDataSize = (unsigned short *)this->m_cPacketBuffer;
		this->m_packetHeader.nProtocolId = (unsigned short *)&this->m_cPacketBuffer[2];
		this->m_cDataBuffer = &this->m_cPacketBuffer[4];
		this->m_nWritePos = 0;
		this->m_nReadPos = 0;
		this->m_nEndPos = 8188;
		this->m_nReceivedSize = 0;
	}

	char * GetPacketBuffer() {
		return this->m_cPacketBuffer;
	}

	char * GetDataBuffer() {
		return this->m_cDataBuffer;
	}

	void CopyToBuffer(char *, int);  

	GamePacket & operator=(GamePacket &packet) {
		this->Clear(0x2000);
		memcpy(this->m_cDataBuffer, packet.m_cDataBuffer, packet.GetDataSize());
		*this->m_packetHeader.nProtocolId = packet.GetId();
		*this->m_packetHeader.nDataSize = packet.GetDataSize();
		return *this;
	}

	GamePacket & operator<<(GamePacket &);

	GamePacket & WriteString(const char *arg) {
		this->WriteData(arg, strlen(arg) + 1);
		return *this;
	}

    GamePacket & Format(const char *fmt, ...) {
        va_list	ap;
	    va_start(ap, fmt);
        char buffer[8192];
        int n = vsnprintf(buffer, sizeof(buffer), fmt, ap);
        if (n == -1) {
            throw SteamEngine::Win32::System::CException("CPacket::Format", "Overflow Buffer");
        }
		this->WriteString(buffer);
        va_end(ap);
		return *this;
	}

	GamePacket & WriteInt(int arg) {
		this->WriteData(&arg, sizeof(int));
		return *this;
	}

	GamePacket & WriteULong(unsigned long arg) {
		this->WriteData(&arg, sizeof(unsigned long));
		return *this;
	}

	GamePacket & WriteUShort(unsigned short arg) {
		this->WriteData(&arg, sizeof(unsigned short));
		return *this;
	}

	GamePacket & WriteUChar(unsigned char arg) {
		this->WriteData(&arg, sizeof(unsigned char));
		return *this;
	}

	GamePacket & operator>>(GamePacket &);

	GamePacket & ReadString(char *arg, unsigned int max_size) {
		unsigned int len = strlen(&this->m_cDataBuffer[this->m_nReadPos]) + 1;
		if (len > max_size) {
			throw SteamEngine::Win32::System::CException("CPacket::ReadString", "Overflow Buffer");
		}

		this->ReadData(arg, len);
		return *this;
	}

	GamePacket & ReadInt(int *arg) {
		this->ReadData(arg, sizeof(int));
		return *this;
	}

    int ReadInt() {
        int v;
		this->ReadData(&v, sizeof(int));
		return v;
    }

	GamePacket & ReadULong(unsigned long *arg) {
		this->ReadData(arg, sizeof(unsigned long));
		return *this;
	}

    unsigned long ReadULong() {
        unsigned long v;
		this->ReadData(&v, sizeof(unsigned long));
		return v;
    }

	GamePacket & ReadUShort(unsigned short *arg) {
		this->ReadData(arg, sizeof(unsigned short));
		return *this;
	}

    unsigned short ReadUShort() {
        unsigned short v;
		this->ReadData(&v, sizeof(unsigned short));
		return v;
    }

	GamePacket & ReadUChar(unsigned char *arg) {
		this->ReadData(arg, sizeof(unsigned char));
		return *this;
	}

    unsigned char ReadUChar() {
        unsigned char v;
		this->ReadData(&v, sizeof(unsigned char));
		return v;
    }

	void ReadData(void *buffer, int size) {
		if ( size + this->m_nReadPos > this->GetDataSize() || size + this->m_nReadPos > this->m_nEndPos) {
			throw SteamEngine::Win32::System::CException("CPacket::ReadData", "Overflow Packet Buffer");
		}
		memcpy(buffer, &this->m_cDataBuffer[this->m_nReadPos], size);
		this->m_nReadPos += size;
	}

	void WriteData(const void *buffer, int size) {
		if (size + this->m_nWritePos > this->m_nEndPos) {
			throw SteamEngine::Win32::System::CException("CPacket::WriteData", "Overflow Packet Buffer");
		}
		memcpy(&this->m_cDataBuffer[this->m_nWritePos], buffer, size);
		this->m_nWritePos += size;
		this->m_nReceivedSize += size;
		*this->m_packetHeader.nDataSize += size;
	}

	int IsReadEnd();


	struct HEADER {
		static const unsigned int _size = 0x8;

		unsigned short * nDataSize;//this+0x0
		unsigned short * nProtocolId;//this+0x4
	};

	struct HEADER m_packetHeader;//this+0x0
	char m_cPacketBuffer[0x2000];//this+0x8
	char * m_cDataBuffer;//this+0x2008
	int m_nReadPos;//this+0x200C
	int m_nWritePos;//this+0x2010
	int m_nEndPos;//this+0x2014
	int m_nReceivedSize;//this+0x2018
};

}//namespace base {



#endif