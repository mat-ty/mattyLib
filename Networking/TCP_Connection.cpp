#include "TCP_Connection.hpp"

TCP_Connection::TCP_Connection()
{
    this->fd = socket(AF_INET, SOCK_STREAM, 0);
    // memset(&this->addr, 0, sizeof(this->addr));
}

TCP_Connection::TCP_Connection(int port, int saddr)
{
    this->fd = socket(AF_INET, SOCK_STREAM, 0);    
    set_addr(port, saddr);
}

TCP_Connection::~TCP_Connection()
{
    close_client();
}

// Getters and Setters

void TCP_Connection::set_fd(int fd)
{
    this->fd = fd;
}

int TCP_Connection::get_fd()
{
    return this->fd;
}

void TCP_Connection::set_addr(int port, int saddr)
{
    memset(&this->addr, 0, sizeof(this->addr));
    this->addr.sin_family = AF_INET;
    this->addr.sin_port = htons(port);
    this->addr.sin_addr.s_addr = htonl(saddr);
}

struct sockaddr_in TCP_Connection::get_addr()
{
    return this->addr;
}




int TCP_Connection::connect_to_server()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        die("socket() failed");
    
    set_fd(sock);

    if (connect(get_fd(), (struct sockaddr *)&get_addr(), sizeof(get_addr())) < 0)
        die("connect() failed");
    
    return get_fd();
}

void TCP_Connection::close_client()
{
    if (get_fd() > 0)
        close(get_fd());
}

