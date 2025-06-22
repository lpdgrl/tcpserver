#include "include/tcpserver.hpp"
#include "include/tcpclient.hpp"

// void AcceptClient(TCPserver& server) {
//     while (true) {
//         server.AcceptClient();
//     }
// }

int main (int argc, char* argv[]) {
    if (argc == 1 || argc <= 2) {
         ::exit(0);
    }

    std::string mode{argv[1]};
    std::string mode_port{argv[2]};

    if (mode == "server" && !(mode_port.empty())) {
        std::string port{argv[2]};
        TCPserver server{port};
        
        server.Start();
        server.Run();

        // std::thread t1(AcceptClient, std::ref(server));
        // // server.AcceptClient();
        // while (true) {
        //     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        //     int recv_bytes = server.Receive();
            
        // }
        // t1.join();
    }

    else if (mode == "client" && !(mode_port.empty())) {
        std::string port{argv[2]};
        TCPclient client{port};

        client.Create();
    
        while (true) {
            client.Send();
        }
    }


    return 0;
}
