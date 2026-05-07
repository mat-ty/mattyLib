#pragma once

#include "TCP_Socket.hpp"

class TCP_Connection : public TCP_Socket {

    private:
    
    public:
        TCP_Connection(int port, int saddr);
        ~TCP_Connection();
        

        int connect_to_server();
        void close_client();

};