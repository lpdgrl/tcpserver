#pragma once

#include <iostream>
#include <cstdint>
#include <string>
#include <cassert>
#include <memory>
#include <utility>
#include <chrono>

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

    int GetFd() const;

    Socket(const Socket& rhs) = delete;
    Socket& operator=(const Socket& rhs) = delete;

    Socket(Socket&& rhs) = delete;
    Socket&& operator=(const Socket&& rhs) = delete;
    virtual void Send(const std::string& msg) const;
    virtual std::string Receive(int dst_fd) const;

protected:
    void GetAddrInfo(const char* name, const char* service, addrinfo& res, addrinfo* pai) const;

protected:
    int socket_fd_{};
};