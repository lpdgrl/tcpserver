#pragma once

#include <list>

#include "socket.hpp"
#include "socketclient.hpp"
#include "socketserver.hpp"

class TCPclient {
public:

    TCPclient() = delete;
    explicit TCPclient(std::string port);

    ~TCPclient() = default;

    void Create();
    void Send();

    // Constructor copy and operator copy is delete
    TCPclient(const TCPclient&) = delete;
    TCPclient& operator=(const TCPclient&) = delete;

    // Constructor move and operator move is delete
    TCPclient(TCPclient&&) = delete;
    TCPclient& operator=(TCPclient&&) = delete;

private:
 

private:
    std::unique_ptr<SocketClient> socket_;
    std::string port_;
};
