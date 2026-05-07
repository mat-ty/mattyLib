#pragma once

#include <vector>

#include "TCP_Client.hpp"
#include "../Sockets/TCP_Listener.hpp"

class TCP_Server
{
    private:
        TCP_Listener listener;
        int queue_size;
        std::vector<TCP_Client> clients;
    
    public:
        TCP_Server(int port, int saddr, int qsize);
        ~TCP_Server();

        int get_queue_size();
        
        void start();
};