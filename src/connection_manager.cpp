#include "../include/connection_manager.hpp"

ConnectionManager::ConnectionManager(SocketServer* server, ClientManager* clients)  {
    if (server != nullptr) {
        server_ = server;
    }
    if (clients != nullptr) {
        clients_ = clients;
    }
}
    
void ConnectionManager::AcceptNewClients() {
    while(true) {
        std::unique_ptr<SocketClient> client;
        client = server_->Accept();

        if (client) {
            clients_->AddClient(std::move(client));
        }
    }
}