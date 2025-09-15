#pragma once

#include <vector>
#include <mutex>

#include "socketserver.hpp"
#include "socketclient.hpp"

struct Client {
    Client() = default;

    int fd_;
    std::unique_ptr<SocketClient> ptr_;
};

class ClientManager {
public:
    // using unordered_map = std::unordered_map<int, std::unique_ptr<SocketClient>>;
    using Clients = std::vector<std::pair<int, std::unique_ptr<SocketClient>>>;

    void AddClient(std::unique_ptr<SocketClient> client);
    void RemoveClient(int fd);
    
    void Receive(int fd);
    void ReceiveFromAll();
    void SendToAll(const std::string& message);

    const Clients& GetClients() const;
    
private:
    Clients clients_;
    std::mutex mtx_client_;
};
