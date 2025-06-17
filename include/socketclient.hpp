#include "socket.hpp"

class SocketClient : public Socket{
public:
    SocketClient();
    explicit SocketClient(char* port);

    ~SocketClient();

    SocketClient(SocketClient&& other);
    SocketClient operator=(SocketClient&& other);

    SocketClient(const SocketClient& other) = delete;
    SocketClient operator=(const SocketClient& other) = delete;

    void Send();
    void Receive();

private: 
    void SendData();
    void ReceiveData();
};