#pragma once

#include "socket.hpp"

class SocketClient : public Socket {
public:
    template<typename T>
    using pointer = std::unique_ptr<T>;    

    SocketClient() = default;
    explicit SocketClient(int fd, sockaddr_storage client_addr);
    
    explicit SocketClient(std::string port);

    ~SocketClient();

    SocketClient(SocketClient&& other);
    SocketClient operator=(SocketClient&& other);

    void CreateSock();
    void Connect(addrinfo* res);

    void Send(const std::string& msg) const override;
    std::string Receive(int dst_fd) const override;

    sockaddr_storage& GetSockAddrStorage();

    std::string GetIp() const;
    std::string GetPort() const;

    SocketClient(const SocketClient& other) = delete;
    SocketClient operator=(const SocketClient& other) = delete;

private: 
    std::pair<std::string, std::string> GetIpAndPort() const ;

private: 
    pointer<sockaddr_storage> client_addr_;
    size_t len_buf_ = 256;
    std::string port_{};
};