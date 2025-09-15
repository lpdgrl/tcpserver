#include "../include/client_manager.hpp"

void ClientManager::AddClient(std::unique_ptr<SocketClient> client) {
    if (client) {   
        std::cout << "### Server ### Client ID " << client->GetFd() << " is accepted. IP: " << client->GetIp() << ". Port: " 
                    << client->GetPort() << std::endl;
        
        clients_.emplace_back(std::make_pair(client->GetFd(), std::move(client)));
    }   
}

void ClientManager::RemoveClient(int fd) {

}

void ClientManager::Receive(int fd) {
    if (clients_.empty() || fd >= clients_.size()) {
        return;
    }
    
    while (true) {
        // std::lock_guard<std::mutex> lk{mtx_client_};
        auto msg = clients_[fd].second->Receive(clients_[fd].first);
        std::cout << "### Server ### Get message from client ID  " << fd << ": \"" << msg << "\"" << std::endl;
    }
}

void ClientManager::ReceiveFromAll() {
    if (clients_.empty()) {
        return;
    }

    // for (auto it = clients_.begin(); it != clients_.end(); ++it) {
    //     auto fd = it->first;
    //     auto msg = it->second->Receive(fd);
    //     std::cout << "### Server ### Gets message: \"" << msg << "\"" << std::endl;
    // }
}

void ClientManager::SendToAll(const std::string& message) {

}

const std::vector<std::pair<int, std::unique_ptr<SocketClient>>>& ClientManager::GetClients() const {
    return clients_;
}