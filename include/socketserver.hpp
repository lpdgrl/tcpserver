#pragma once 

#include "socket.hpp"
#include "socketclient.hpp"

class SocketServer : public Socket{
public:
    template<typename T>
    using pointer = std::unique_ptr<T>;    

    SocketServer() = delete;
    explicit SocketServer(std::string port);

    ~SocketServer();

    SocketServer(SocketServer&& other);
    SocketServer operator=(SocketServer&& other);

    SocketServer(const SocketServer& other) = delete;
    SocketServer operator=(const SocketServer& other) = delete;

    void Create();
    void Listen();
    pointer<SocketClient> Accept();
    
    void Send(const std::string& msg) const override;
    std::string Receive(int dst_int) const override;

    
private:
    void CreateSock();
    void BindSocket(addrinfo* hints);
    void ListenSocket();
    
private:
    std::string port_{};
    size_t backlog_ = 10;
    size_t len_buf_ = 256;
};