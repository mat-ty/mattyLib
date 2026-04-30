#pragma once

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

namespace mg
{

    /**
     *  
     *  Create the socket
        Identify the socket
        On the server, wait for an incoming connection
        Send and receive messages
        Close the socket
     */
    class SimpleSocket
    {
        

    // struct sockaddr_in {
	// __uint8_t       sin_len;
	// sa_family_t     sin_family;
	// in_port_t       sin_port;
	// struct  in_addr sin_addr;
	// char            sin_zero[8];
    // };

    private:
        int sock;
        int connection;
        struct sockaddr_in address;


    public:
        SimpleSocket(int domain, int service, int protocol, int port,
        u_long user_interface);
        virtual int connect_to_network(int sock, struct sockaddr_in addr ) = 0;
        void test_connection(int test_sock);
        struct sockaddr_in get_address();
        int get_connection();
        


        ~SimpleSocket(); 
    };
    

}