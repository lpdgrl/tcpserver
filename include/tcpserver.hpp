#include "socket.hpp"

class TCPserver {
public:

    TCPserver();
    TCPserver(std::string port);

    // Constructor copy and operator copy is delete
    TCPserver(const TCPserver&) = delete;
    TCPserver& operator=(const TCPserver&) = delete;

    // Constructor move and operator move is delete
    TCPserver(TCPserver&&) = delete;
    TCPserver& operator=(TCPserver&&) = delete;

    ~TCPserver();

    void Create();

private:
 

private:
    Socket socket_;
    std::string port_;
};
