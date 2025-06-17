#pragma once

#include <iostream>
#include <cstdint>
#include <string>
#include <cassert>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

class Socket {
public:
    Socket();

    ~Socket();

    int GetSFd();

protected:
    void GetAddrInfo(const char* name, const char* service, addrinfo& res, addrinfo* pai);

protected:
    int socket_fd_;
};