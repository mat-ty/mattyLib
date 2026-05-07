#pragma once

#include <vector>
#include <iostream>

#include "TCP_Client.hpp"
#include "../Sockets/TCP_Listener.hpp"

class TCP_Server
{
    private:
        TCP_Listener listener;
        int queue_size;
        std::vector<int> client_fds;
    
    public:
        TCP_Server(int port, int saddr, int qsize);
        ~TCP_Server();

        int get_queue_size();
        
        void start();
        void stop();

        int accept_client();
        void close_client(int client_fd);
        void write_to_client(int client_fd, const std::string &message);
        std::string read_from_client(int client_fd);  

    }; 