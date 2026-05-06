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

class TCP_Listener{

    private:
        int fd;
        struct sockaddr_in addr;
        int queue_size;

        void die(const char *);
    
    public:
        TCP_Listener();
        TCP_Listener(int port, int saddr, int qsize);
        ~TCP_Listener();

        void set_fd(int fd);
        void set_addr(int port, int saddr);
        int get_fd();
        struct sockaddr_in get_addr();
        int get_queue_size();
        
        int start();
        void close_listener();

};