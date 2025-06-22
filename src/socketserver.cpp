#include "../include/socketserver.hpp"

SocketServer::SocketServer(std::string port) : port_{port} {
}

SocketServer::~SocketServer() {
}

void SocketServer::Create() {
    CreateSock();
}

void SocketServer::Listen() {
    ListenSocket();
}

std::unique_ptr<SocketClient> SocketServer::Accept() {
    sockaddr_storage client_addr{};
    socklen_t addr_size = sizeof(client_addr);

    int client_fd = accept(socket_fd_, reinterpret_cast<sockaddr*>(&client_addr), &addr_size);
    
    if (client_fd == -1) {
        return nullptr;
    }

    std::cout << "### Server ### Client was accepted" << std::endl; 
    
    return std::make_unique<SocketClient>(client_fd, client_addr);
}

void SocketServer::CreateSock() {
    addrinfo hints{};
    addrinfo* res = nullptr;

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // GetAddrInfo(NULL, port_.data(), hints, res);
    ::getaddrinfo(NULL, port_.data(), &hints, &res);
    socket_fd_ = ::socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    assert(socket_fd_ != -1);

    int option = 1;
    int succes_set_opt_sock = setsockopt(socket_fd_, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(int));
    assert(succes_set_opt_sock != -1);

    BindSocket(res);

    freeaddrinfo(res);
}

void SocketServer::BindSocket(addrinfo* hints) {
    assert(socket_fd_ != -1);

    int succes_bind = ::bind(socket_fd_, hints->ai_addr, hints->ai_addrlen);
    assert(succes_bind != -1);
}

void SocketServer::ListenSocket() {
    int succes_set_listen = ::listen(socket_fd_, backlog_);
    assert(succes_set_listen != -1);
}


void SocketServer::Send(const std::string& msg) const {
    const char* c_msg = msg.data();
    int send_bytes = ::send(socket_fd_, c_msg, len_buf_, 0);

    std::cout << "### Server ### Count is sending bytes: " << send_bytes << std::endl;
}

std::string SocketServer::Receive(int dst_fd) const {
    char buffer[len_buf_];

    int recv_bytes = recv(dst_fd, buffer, len_buf_, 0);
    std::cout << recv_bytes << std::endl;
    if (recv_bytes <= 0) {
        return {};
    }

    std::cout << "### Server ### Count is receiving bytes: " << recv_bytes << std::endl;
    return {buffer};
}

