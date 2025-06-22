#pragma once

#include <unordered_map>

#include "socketserver.hpp"
#include "socketclient.hpp"

class ClientManager {
public:
    using unordered_map = std::unordered_map<int, std::unique_ptr<SocketClient>>;

    void AddClient(std::unique_ptr<SocketClient> client);
    void RemoveClient(int fd);

    void ReceiveFromAll();
    void SendToAll(const std::string& message);

    const unordered_map& GetClients() const;

private:
    unordered_map clients_;
};
