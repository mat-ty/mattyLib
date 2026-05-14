#pragma once

#include "TCP_Socket.hpp"

#include <iostream>

class TCP_Connection : public TCP_Socket {

    private:
    
    public:
        TCP_Connection();
        TCP_Connection(int port, int saddr);
        ~TCP_Connection();
        

        int connect_to_host();
        void close_connection();

};