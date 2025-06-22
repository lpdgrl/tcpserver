#pragma once

#include "socketserver.hpp"
#include "client_manager.hpp"

class ConnectionManager {
public:
    explicit ConnectionManager(SocketServer* server, ClientManager* clients); 
    
    void AcceptNewClients();

private:
    SocketServer* server_;
    ClientManager* clients_;
};
