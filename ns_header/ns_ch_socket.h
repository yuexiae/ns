#ifndef NSHEADER_NS_CH_SOCKET_H_
#define NSHEADER_NS_CH_SOCKET_H_

#include <winsock2.h>

class CChSocket {
public:
	static const unsigned int _size = 0x20;

	CChSocket(const CChSocket &);
	CChSocket(int);    PATCH_MEMBER(CChSocket &, Constructor, int, 0x409D90);
	virtual ~CChSocket();    PATCH_MEMBER(void, Destructor, , 0x409DD0);
	unsigned int GetHandle();    PATCH_MEMBER(unsigned int, GetHandle, , 0x402B90);
	void SetHandle(unsigned int);
	static int Init(unsigned short);    PATCH_STATIC(int, Init, unsigned short, 0x409DF0);
	static void End();    PATCH_STATIC(void, End, , 0x409E40);
	sockaddr_in * MakeSocketAddr(unsigned char, unsigned char, unsigned char, unsigned char, unsigned short);    PATCH_MEMBER(sockaddr_in *, MakeSocketAddr, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short, 0x40A2E0);
	sockaddr_in * MakeSocketAddr(char *, unsigned short);    PATCH_MEMBER(sockaddr_in *, MakeSocketAddr, char * _COMMA unsigned short, 0x40A200);
	int Create();    PATCH_MEMBER(int, Create, , 0x409E50);
	int Create(char *, unsigned short);    PATCH_MEMBER(int, Create, char * _COMMA unsigned short, 0x40A350);
	void Close();    PATCH_MEMBER(void, Close, , 0x409EE0);
	int Connect(sockaddr_in);    PATCH_MEMBER(int, Connect, sockaddr_in, 0x409F60);
	int Connect();    PATCH_MEMBER(int, Connect, , 0x409F20);
	int Bind(sockaddr_in);    PATCH_MEMBER(int, Bind, sockaddr_in, 0x40A110);
	int Bind();    PATCH_MEMBER(int, Bind, , 0x40A0D0);
	int Listen(int);    PATCH_MEMBER(int, Listen, int, 0x40A140);
	int Recv(char *, int, sockaddr *, int *);    PATCH_MEMBER(int, Recv, char * _COMMA int _COMMA sockaddr * _COMMA int *, 0x40A1A0);
	int Recv(char *, int);    PATCH_MEMBER(int, Recv, char * _COMMA int, 0x40A170);
	int RecvEx(char *, int);    PATCH_MEMBER(int, RecvEx, char * _COMMA int, 0x40A3C0);
	int Send(char *, int, sockaddr *, int);    PATCH_MEMBER(int, Send, char * _COMMA int _COMMA sockaddr * _COMMA int, 0x40A1D0);
	int Send(char *, int);    PATCH_MEMBER(int, Send, char * _COMMA int, 0x40A430);
	int GetConnectTimeOut();
	void SetConnectTimeOut(int);    PATCH_MEMBER(void, SetConnectTimeOut, int, 0x402B70);
	void SetRecvTimeOut(int);    PATCH_MEMBER(void, SetRecvTimeOut, int, 0x409E80);
	void SetSendTimeOut(int);    PATCH_MEMBER(void, SetSendTimeOut, int, 0x409EB0);
	unsigned int m_sock;//this+0x4
	int m_nType;//this+0x8
	int m_nConnectTimeOut;//this+0xC
	struct sockaddr_in m_sa;//this+0x10
	CChSocket & operator=(const CChSocket &);
	//void __dflt_ctor_closure();
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CChSocket &, CChSocket, Constructor, int);
	PATCH_MEMBER_INVOKE(void, CChSocket, Destructor, );
	PATCH_MEMBER_INVOKE(unsigned int, CChSocket, GetHandle, );
	PATCH_STATIC_INVOKE(int, Init, unsigned short);
	PATCH_STATIC_INVOKE(void, End, );
	PATCH_MEMBER_INVOKE(sockaddr_in *, CChSocket, MakeSocketAddr, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short);
	PATCH_MEMBER_INVOKE(sockaddr_in *, CChSocket, MakeSocketAddr, char * _COMMA unsigned short);
	PATCH_MEMBER_INVOKE(int, CChSocket, Create, );
	PATCH_MEMBER_INVOKE(int, CChSocket, Create, char * _COMMA unsigned short);
	PATCH_MEMBER_INVOKE(void, CChSocket, Close, );
	PATCH_MEMBER_INVOKE(int, CChSocket, Connect, sockaddr_in);
	PATCH_MEMBER_INVOKE(int, CChSocket, Connect, );
	PATCH_MEMBER_INVOKE(int, CChSocket, Bind, sockaddr_in);
	PATCH_MEMBER_INVOKE(int, CChSocket, Bind, );
	PATCH_MEMBER_INVOKE(int, CChSocket, Listen, int);
	PATCH_MEMBER_INVOKE(int, CChSocket, Recv, char * _COMMA int _COMMA sockaddr * _COMMA int *);
	PATCH_MEMBER_INVOKE(int, CChSocket, Recv, char * _COMMA int);
	PATCH_MEMBER_INVOKE(int, CChSocket, RecvEx, char * _COMMA int);
	PATCH_MEMBER_INVOKE(int, CChSocket, Send, char * _COMMA int _COMMA sockaddr * _COMMA int);
	PATCH_MEMBER_INVOKE(int, CChSocket, Send, char * _COMMA int);
	PATCH_MEMBER_INVOKE(void, CChSocket, SetConnectTimeOut, int);
	PATCH_MEMBER_INVOKE(void, CChSocket, SetRecvTimeOut, int);
	PATCH_MEMBER_INVOKE(void, CChSocket, SetSendTimeOut, int);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CChSocket::Constructor(int), 0x409D90);
	//DEFINE_NAKED_JMP(CChSocket::Destructor(), 0x409DD0);
	//DEFINE_NAKED_JMP(unsigned int CChSocket::GetHandle(), 0x402B90);
	//DEFINE_NAKED_JMP(int CChSocket::Init(unsigned short), 0x409DF0);
	//DEFINE_NAKED_JMP(void CChSocket::End(), 0x409E40);
	//DEFINE_NAKED_JMP(sockaddr_in * CChSocket::MakeSocketAddr(unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short), 0x40A2E0);
	//DEFINE_NAKED_JMP(sockaddr_in * CChSocket::MakeSocketAddr(char * _COMMA unsigned short), 0x40A200);
	//DEFINE_NAKED_JMP(int CChSocket::Create(), 0x409E50);
	//DEFINE_NAKED_JMP(int CChSocket::Create(char * _COMMA unsigned short), 0x40A350);
	//DEFINE_NAKED_JMP(void CChSocket::Close(), 0x409EE0);
	//DEFINE_NAKED_JMP(int CChSocket::Connect(sockaddr_in), 0x409F60);
	//DEFINE_NAKED_JMP(int CChSocket::Connect(), 0x409F20);
	//DEFINE_NAKED_JMP(int CChSocket::Bind(sockaddr_in), 0x40A110);
	//DEFINE_NAKED_JMP(int CChSocket::Bind(), 0x40A0D0);
	//DEFINE_NAKED_JMP(int CChSocket::Listen(int), 0x40A140);
	//DEFINE_NAKED_JMP(int CChSocket::Recv(char * _COMMA int _COMMA sockaddr * _COMMA int *), 0x40A1A0);
	//DEFINE_NAKED_JMP(int CChSocket::Recv(char * _COMMA int), 0x40A170);
	//DEFINE_NAKED_JMP(int CChSocket::RecvEx(char * _COMMA int), 0x40A3C0);
	//DEFINE_NAKED_JMP(int CChSocket::Send(char * _COMMA int _COMMA sockaddr * _COMMA int), 0x40A1D0);
	//DEFINE_NAKED_JMP(int CChSocket::Send(char * _COMMA int), 0x40A430);
	//DEFINE_NAKED_JMP(void CChSocket::SetConnectTimeOut(int), 0x402B70);
	//DEFINE_NAKED_JMP(void CChSocket::SetRecvTimeOut(int), 0x409E80);
	//DEFINE_NAKED_JMP(void CChSocket::SetSendTimeOut(int), 0x409EB0);
#endif
};





#endif