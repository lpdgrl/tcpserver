#include "../include/tcpclient.hpp"

TCPclient::TCPclient(std::string port) : port_{port} {
    socket_ = std::make_unique<SocketClient>(port);
}

void TCPclient::Create() {
    std::cout << "### Client ### TCPclient is starting..." << std::endl;
    socket_->CreateSock();
    std::cout << "### Client ### TCPclient was succesfully started." << std::endl;
}

void TCPclient::Send() {
    std::string msg;

    std::getline(std::cin, msg);

    socket_->Send(msg);
    
    std::cout << "### Client ### Client is sending message." << std::endl;
}