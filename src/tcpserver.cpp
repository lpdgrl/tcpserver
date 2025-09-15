#include "../include/tcpserver.hpp"

TCPserver::TCPserver(std::string port) : port_{port} {
    socket_ = std::make_unique<SocketServer>(port);
    client_manager_ = std::make_unique<ClientManager>();
    conn_manager_ = std::make_unique<ConnectionManager>(socket_.get(), client_manager_.get());
}   

void TCPserver::Create() {
    std::cout << "### Server ### TCPserver is starting..." << std::endl;
    socket_->Create();
    socket_->Listen();
    std::cout << "### Server ### TCPserver was succesfully started." << std::endl;
}

void TCPserver::PrintConnectedUsers() const {
    const auto& clients = client_manager_->GetClients();

    int id = 1;

    std::cout << "### Server ### Print all users was connected to server." << std::endl;
    for (const auto& el : clients) {
        std::cout << "\tClient ID " << id++ << " IP address of client: " << el.second->GetIp() << " Port: " 
        << el.second->GetPort() << " Socket ID: " << el.first << std::endl;
    }
}

void TCPserver::Start() {
    Create();
    running_ = true;
}

void TCPserver::Worker() {

}

void TCPserver::Run() {
    std::thread accept_clients(&ConnectionManager::AcceptNewClients, conn_manager_.get()); 
    accept_clients.detach();

    size_t count_clients = 0;

    while (running_) {
        // conn_manager_->AcceptNewClients();
        size_t tmp_count_clients = client_manager_->GetClients().size();
        if (tmp_count_clients > count_clients) {
            count_clients = tmp_count_clients;

            std::thread worker(&ClientManager::Receive, client_manager_.get(), tmp_count_clients - 1);
            worker.detach();
        }
    }
    
}

void TCPserver::Stop() {

}

void TCPserver::Restart() {

}

void TCPserver::GetStatus() const {

}