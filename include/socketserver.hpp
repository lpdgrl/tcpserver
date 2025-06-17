#include "socket.hpp"
#include "socketclient.hpp"

class SocketServer : public Socket{
public:
    SocketServer() = delete;
    explicit SocketServer(char* port);

    ~SocketServer() = default;

    SocketServer(SocketServer&& other);
    SocketServer operator=(SocketServer&& other);

    SocketServer(const SocketServer& other) = delete;
    SocketServer operator=(const SocketServer& other) = delete;

    void Create();
    // void Listen();
    SocketClient Accept();

private:
    void CreateSock();
    void BindSocket(addrinfo& hints);
    void ListenSocket();
    SocketClient AcceptClient();
    
private:
    char* port_;
    size_t backlog_ = 10;
};