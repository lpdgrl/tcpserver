#pragma once 

#include <list>
#include <deque>
#include <thread>
#include <mutex>

#include "socket.hpp"
#include "socketclient.hpp"
#include "socketserver.hpp"
#include "connection_manager.hpp"
#include "client_manager.hpp"

class TCPserver {
public:

    TCPserver() = delete;
    explicit TCPserver(std::string port);

    ~TCPserver() = default;

    void PrintConnectedUsers() const;

    void Start();
    void Run();
    void Stop();
    void Restart();

    void GetStatus() const;

    // Constructor copy and operator copy is delete
    TCPserver(const TCPserver&) = delete;
    TCPserver& operator=(const TCPserver&) = delete;

    // Constructor move and operator move is delete
    TCPserver(TCPserver&&) = delete;
    TCPserver& operator=(TCPserver&&) = delete;

private:
    void Create();
    void Worker();

private:
    bool running_ = false;
    std::unique_ptr<SocketServer> socket_;
    std::unique_ptr<ClientManager> client_manager_;
    std::unique_ptr<ConnectionManager> conn_manager_;
    std::string port_;
};
