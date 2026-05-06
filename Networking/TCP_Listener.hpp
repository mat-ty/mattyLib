#pragma once

#include "TCP_Socket.hpp"

class TCP_Listener : public TCP_Socket {

    private:
        int queue_size;
    
    public:
        TCP_Listener();
        TCP_Listener(int port, int saddr, int queue_size);
        ~TCP_Listener();

        int get_queue_size();
        void set_queue_size(int qsize); 

        int start();
        void close_listener();

};