#include "../include/socketclient.hpp"

SocketClient::SocketClient(int fd, sockaddr_storage client_addr) {   
    socket_fd_ = fd;
    client_addr_ = std::make_unique<sockaddr_storage>(client_addr);
}

SocketClient::SocketClient(std::string port) : Socket(), port_{port} {}


SocketClient::~SocketClient() {}

void SocketClient::CreateSock() {
    addrinfo hints{};
    addrinfo* res{};

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
    int success_geaddrinfo = ::getaddrinfo("localhost", port_.data(), &hints, &res);
    assert(success_geaddrinfo != -1);

    socket_fd_ = ::socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    assert(socket_fd_ != -1);

    Connect(res);
}

void SocketClient::Connect(addrinfo* res) {
    int error_connect = ::connect(socket_fd_, res->ai_addr, res->ai_addrlen);
    assert(error_connect != -1);
    std::cout << "### Client ### Client ID " << socket_fd_ << " was connected to server" << std::endl;
}

sockaddr_storage& SocketClient::GetSockAddrStorage() {
    return *client_addr_;
}

std::pair<std::string, std::string> SocketClient::GetIpAndPort() const{
    sockaddr_in peer_addr{};
    socklen_t addr_len = sizeof(peer_addr);

    getpeername(socket_fd_, reinterpret_cast<sockaddr*>(&peer_addr), &addr_len);
    char ip_str[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &peer_addr.sin_addr, ip_str, sizeof(ip_str));
 
    return std::make_pair(std::string(ip_str), std::to_string(ntohs(peer_addr.sin_port)));
}

std::string SocketClient::GetIp() const {
    return GetIpAndPort().first;
}

std::string SocketClient::GetPort() const {
    return GetIpAndPort().second;
}

void SocketClient::Send(const std::string& msg) const {
    const char* c_msg = msg.data();
    int send_bytes = ::send(socket_fd_, c_msg, len_buf_, 0);

    std::cout << "### Client ### Client ID " << socket_fd_ << "  is sending bytes: " << send_bytes << std::endl;
}

std::string SocketClient::Receive(int dst_fd) const {
    char buffer[len_buf_];

    int recv_bytes = recv(socket_fd_, buffer, len_buf_, 0);

    if (recv_bytes <= 0) {
        return {};
    }
    
    std::cout << "### Client ### Client ID " << socket_fd_ << " is receiving bytes: " << recv_bytes << std::endl;
    return {buffer};
}