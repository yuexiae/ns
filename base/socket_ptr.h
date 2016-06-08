#ifndef BASE_SOCKET_UTIL_H_
#define BASE_SOCKET_UTIL_H_


#ifdef _WIN32
#include <winsock2.h>
#include <mstcpip.h>
#else
#include <arpa/inet.h>
#endif

#if defined(_MSC_VER) && _MSC_VER < 1600
    typedef __int8 int8_t;
    typedef unsigned __int8 uint8_t;
    typedef __int16 int16_t;
    typedef unsigned __int16 uint16_t;
    typedef __int32 int32_t;
    typedef unsigned __int32 uint32_t;
    typedef __int64 int64_t;
    typedef unsigned __int64 uint64_t;
#elif defined(_MSC_VER)  // && _MSC_VER >= 1600
#   include <stdint.h>
#else
#   include <stdint.h>
#   include <stdbool.h>
#endif

#include "base/buffer.h"

namespace base {


class SocketPtrWin {
public:
    SocketPtrWin() : fd_(INVALID_SOCKET), error_no_() { }

    ~SocketPtrWin() {
        if (fd_ != INVALID_SOCKET){
			::shutdown(fd_, SD_BOTH);
			::closesocket(fd_);
			fd_ = INVALID_SOCKET;
		}
    }

    static void SocketInit() {
        WSADATA wsa = {0};
        WSAStartup(MAKEWORD(2, 2), &wsa);
    }

    bool Create(int family, int type, int protocol) {
        fd_ = ::socket(family, type, protocol);
        if (fd_ == INVALID_SOCKET) {
            error_no_ = ::WSAGetLastError();
            return false;
        }

        return true;
    }

    bool Connect(const char *host, uint16_t port) {
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sockaddr_in));
		sin.sin_family = AF_INET;
		sin.sin_port = ::htons(port);
		sin.sin_addr.S_un.S_addr = GetHost(host);

		if (connect(fd_, (sockaddr *)&sin, sizeof(sockaddr_in)) < 0) {
            error_no_ = ::WSAGetLastError();
            ::closesocket(fd_);
			fd_ = INVALID_SOCKET;
			return false;
		}

        return true;
    }

    bool SetTCPKeepAlive(bool enable, int delay_secs) {
        int val = 1;

        if (::setsockopt(fd_, SOL_SOCKET, SO_KEEPALIVE, reinterpret_cast<const char*>(&val), sizeof(val)) == -1){
           error_no_ = ::WSAGetLastError();
           return false;
        }

        unsigned delay = delay_secs * 1000;
        struct tcp_keepalive keepalive_vals = {enable ? 1u : 0u, delay, delay,  };

        DWORD bytes_returned = 0xABAB;
        if (::WSAIoctl(fd_, SIO_KEEPALIVE_VALS, &keepalive_vals,
            sizeof(keepalive_vals), NULL, 0, &bytes_returned, NULL, NULL) == -1) {
            error_no_ = ::WSAGetLastError();
            return false;
        }

        return true;
    }

    bool DisableNagle(bool disable) {
        BOOL val = disable ? TRUE : FALSE;
        if (::setsockopt(fd_, IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<const char*>(&val), sizeof(val)) == -1) {
            error_no_ = ::WSAGetLastError();
            return false;
        }

        return true;
    }

    bool SetSocketReceiveBufferSize(int32_t size) {
        if (::setsockopt(fd_, SOL_SOCKET, SO_RCVBUF, reinterpret_cast<const char*>(&size), sizeof(size)) == -1) {
            error_no_ = ::WSAGetLastError();
            return false;
        }
        return true;
    }

    bool SetSocketSendBufferSize(SOCKET socket, int32_t size) {
        if (::setsockopt(fd_, SOL_SOCKET, SO_SNDBUF, reinterpret_cast<const char*>(&size), sizeof(size)) == -1) {
            error_no_ = ::WSAGetLastError();
            return false;
        }
        return true;
    }

    bool SetTimeOut(int secs) {
        struct timeval tv = { secs * 1000, 0 };
        if (setsockopt(fd_, SOL_SOCKET,SO_RCVTIMEO, reinterpret_cast<const char*>(&tv), sizeof(tv)) == -1) {
            error_no_ = ::WSAGetLastError();
            return false;
        }
        if (setsockopt(fd_, SOL_SOCKET,SO_SNDTIMEO, reinterpret_cast<const char*>(&tv), sizeof(tv)) == -1) {
            error_no_ = ::WSAGetLastError();
            return false;
        }
        return true;
    }

    int Recv(char *dst, int len) {
        int n = recv(fd_, dst, len, 0);
        if (n <= 0) {
            error_no_ = ::WSAGetLastError();
            return n;
        }

        return n;
    }

    int Send(const char *buffer, int len) {
        int left = len;
        while (left > 0){
            int n = send(fd_, buffer, left, 0);
            if (n < 0)
                return n;
            left -= n;
            buffer += n;
        }
        return len - left;
    }

    int GetErrorCode() {
        return error_no_;
    }

    
private:
    unsigned long GetHost(const char *hostname) {
		long ip;
		ip = inet_addr(hostname);
        if(ip > 0) {
			return ip ;
        }

		struct hostent *host;
		host = (struct hostent*)::gethostbyname(hostname);
		if(host != NULL) {
			return *(unsigned long *)host->h_addr;
		}

		return 0;
	}

    int fd_;
    int error_no_;
};



typedef SocketPtrWin SocketPtr;




}








#endif