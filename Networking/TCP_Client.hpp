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

#include "TCP_Connection.hpp"

class TCP_Client{

    private:
        TCP_Connection connection;    

    public:
        TCP_Client();
        TCP_Client(int port, int saddr);
        ~TCP_Client();

        int connect_to_server();
        void close_client();
    

};