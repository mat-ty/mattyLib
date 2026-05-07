#include "TCP_Socket.hpp"

void TCP_Socket::die(const char *message)
{
    close_socket();
    perror(message);
    exit(EXIT_FAILURE);
}

TCP_Socket::TCP_Socket() : fd(-1), addr{}
{
    addr.sin_family = AF_INET;
}

TCP_Socket::TCP_Socket(uint16_t port, uint32_t saddr)
 : fd(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)), addr{}
{
    if (fd < 0)
    {
        die("socket() failed");
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = port;
    addr.sin_addr.s_addr = saddr;
}

TCP_Socket::~TCP_Socket()
{
    close_socket();
}

void TCP_Socket::close_socket()
{
    if (this->fd != -1)
    {
        close(this->fd);
        this->fd = -1;
    }
}

const int TCP_Socket::get_fd()
{
    return fd;
}

void TCP_Socket::set_fd(int fd)
{
    if (this->fd != -1)
    {
        close(this->fd);
    }
    this->fd = fd;
}

const struct sockaddr_in TCP_Socket::get_addr()
{
    return addr;
}

void TCP_Socket::set_addr(uint16_t port, uint32_t saddr)
{
    this->addr.sin_port = port;
    this->addr.sin_addr.s_addr = saddr;
}
