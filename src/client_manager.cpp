#include "../include/client_manager.hpp"

void ClientManager::AddClient(std::unique_ptr<SocketClient> client) {
    if (client) {
        std::cout << "### Server ### Client ID " << client->GetFd() << " is accepted. IP: " << client->GetIp() << ". Port: " 
                    << client->GetPort() << std::endl;

        clients_.emplace(std::make_pair(client->GetFd(), std::move(client)));
    }   
}

void ClientManager::RemoveClient(int fd) {

}

void ClientManager::ReceiveFromAll() {
    if (clients_.empty()) {
        return;
    }

    for (auto it = clients_.begin(); it != clients_.end(); ++it) {
        auto fd = it->first;
        auto msg = it->second->Receive(fd);
        std::cout << "### Server ### Gets message: \"" << msg << "\"" << std::endl;
    }
}

void ClientManager::SendToAll(const std::string& message) {

}

const std::unordered_map<int, std::unique_ptr<SocketClient>>& ClientManager::GetClients() const {
    return clients_;
}