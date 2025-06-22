#include "../include/socket.hpp"

Socket::Socket() {
}

Socket::~Socket() {
    if (socket_fd_ > 0) {
        ::close(socket_fd_);
    }
}

void Socket::GetAddrInfo(const char* name, const char* service, addrinfo& hints, addrinfo* res) const {
    int status = ::getaddrinfo(NULL, service, &hints, &res);
    if (status == -1) {
        std::cerr << "geaddrinfo: " << std::endl << gai_strerror(status) << std::endl;
    }
}

int Socket::GetFd() const {
    return socket_fd_;
}

void Socket::Send(const std::string& msg) const {

}

std::string Socket::Receive(int dst_fd) const {
    return {};
}