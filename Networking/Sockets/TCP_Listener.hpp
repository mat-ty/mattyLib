#pragma once

#include "TCP_Socket.hpp"

class TCP_Listener : public TCP_Socket {

    private:
        int queue_size;
    
    public:
        TCP_Listener();
        TCP_Listener(int port, int saddr, int queue_size);
        ~TCP_Listener();

        const int get_queue_size();

        int accept_connection();
        int start();
        void close_listener();

};