#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>

#include "TCP_Socket.hpp"

class TCP_Connection : public TCP_Socket {

    private:
    
    public:
        TCP_Connection();
        TCP_Connection(int port, int saddr);
        ~TCP_Connection();


        int connect_to_server();
        void close_client();

};