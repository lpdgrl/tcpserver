#include "../include/socketserver.hpp"

SocketServer::SocketServer() {
   
}

explicit SocketServer::SocketServer(char* port_) {

}


void SocketServer::Create() {
    CreateSock();
}

void SocketServer::CreateSock() {
    addrinfo hints{};
    addrinfo* res = nullptr;

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    GetAddrInfo(NULL, port_, hints, res);

    socket_fd_ = ::socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    assert(socket_fd_ == -1);
    
    BindSocket(hints);

    freeaddrinfo(res);
}

void SocketServer::BindSocket(addrinfo& hints) {
    assert(socket_fd_ == -1);

    int succes_bind = ::bind(socket_fd_, hints.ai_addr, hints.ai_addrlen);
    assert(succes_bind == -1);
}

void SocketServer::ListenSocket() {
    int succes_set_listen = ::listen(socket_fd_, backlog_);
    assert(succes_set_listen == -1);
}