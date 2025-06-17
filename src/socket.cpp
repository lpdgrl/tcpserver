#include "../include/socket.hpp"

Socket::Socket() {
    
}

Socket::~Socket() {
    ::close(socket_fd_);
}

void Socket::GetAddrInfo(const char* name, const char* service, addrinfo& hints, addrinfo* res) {
    int status = getaddrinfo(name, service, &hints, &res);
    if (status == -1) {
        std::cerr << "geaddrinfo: " << std::endl << gai_strerror(status) << std::endl;
    }
}
