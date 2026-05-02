#pragma once

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>


/** NOTES
 * 
 * The simple socket class should represent the most generalized form for all socket connections
 *      Every network connection will need a...
 *      - socket
 *      - connection
 *      - address information
 * 
 *      From there we can create children classes for each specific type of socket connection 
 *      we will need. I.E. Client vs Server
 * 
 * 
 * Sofar, since we are only binding a
 * 
 */

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
        
        // Client and Servers use different methods/params to connect to networks
        virtual int connect_to_network(int sock, struct sockaddr_in addr ) = 0;
        //Tests socket and connection
        void test_connection(int test_sock);
        //Getter functions
        struct sockaddr_in get_address();
        int get_sock();
        int get_connection();

        //Setter Functions
        void set_connection(int conn);


        // When a class has virtual functions, the destructor should also be virtual?
        // 
        // virtual ~SimpleSocket(); 
    };
    

}