#include "SimpleSocket.hpp"

mg::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port,
                                u_long user_interface)
{
// Define address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(user_interface); 
// Establish connection
    int sock = socket(domain, service, protocol);
    test_connection(sock);

    connection = connect_to_network(sock, address);

}

void mg::SimpleSocket::test_connection(int test_sock){
    if (test_sock<0)
    {
        perror("Connection not established.");
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in mg::SimpleSocket::get_address(){
    return address;
}
int mg::SimpleSocket::get_connection(){
    return connection;
}
int mg::SimpleSocket::get_sock(){
    return sock;
}
