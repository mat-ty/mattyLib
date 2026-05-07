#pragma once

#include "../Sockets/TCP_Connection.hpp"

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