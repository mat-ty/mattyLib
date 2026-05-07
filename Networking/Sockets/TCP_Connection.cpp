#include "TCP_Connection.hpp"

TCP_Connection::TCP_Connection(int port, int saddr) : TCP_Socket(ntohs(port), ntohl(saddr))
{

}

TCP_Connection::~TCP_Connection()
{
    close_client();
}



int TCP_Connection::connect_to_server()
{
    if (connect(get_fd(), (const struct sockaddr *)&this->get_addr(), sizeof(this->get_addr())) == -1)
    {
        die("Connection failed");
    }
    return get_fd();
}

void TCP_Connection::close_client()
{
    close_socket();
}

