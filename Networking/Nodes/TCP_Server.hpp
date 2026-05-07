#pragma once

#include <vector>
#include "../Sockets/TCP_Listener.hpp"

class TCP_Server
{
    private:
        TCP_Listener listener;
        int queue_size;
        std::vector<struct sockaddr_in> client_fds;
    
    public:
        TCP_Server();
        TCP_Server(int port, int saddr, int qsize);
        ~TCP_Server();

        void set_queue_size(int qsize);
        int get_queue_size();
        
        void start();
};