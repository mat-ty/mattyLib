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

class TCP_Socket{

    private:
        int fd;
        struct sockaddr_in addr;

    protected:
        void die(const char *);
        void close_socket();

    public:
        TCP_Socket();
        TCP_Socket(uint16_t port, uint32_t saddr);
        ~TCP_Socket();

        void set_fd(int fd);
        const int get_fd();
        void set_addr(struct sockaddr_in addr);
        const struct sockaddr_in get_addr();

};