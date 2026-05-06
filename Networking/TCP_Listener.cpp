#include "TCP_Listener.hpp"

TCP_Listener::TCP_Listener(){
    this->fd = -1;
    this->queue_size = 1;
}

TCP_Listener::TCP_Listener(int port, int saddr, int qsize){
    this->fd = socket(AF_INET, SOCK_STREAM, 0);

    this->addr.sin_family = AF_INET;
    this->addr.sin_port = ntohs(port);
    this->addr.sin_addr.s_addr = ntohl(saddr);
    this->queue_size = qsize;
}

TCP_Listener::~TCP_Listener(){
    if(this->fd!=-1){
        close(this->fd);
    }
}


// Setters and Getters
void TCP_Listener::set_fd(int fd){

    if(fd!=-1){
        close(this->fd);
    }

    this->fd = fd;
}

void TCP_Listener::set_addr(int port, int saddr){
    this->addr.sin_family = AF_INET;
    this->addr.sin_port = ntohs(port);
    this->addr.sin_addr.s_addr = ntohl(saddr);
}

int TCP_Listener::get_fd(){
    return this->fd;
}

struct sockaddr_in TCP_Listener::get_addr(){
    return this->addr;
}

int TCP_Listener::get_queue_size(){
    return this->queue_size;
}

// Utility function to print error and exit
void TCP_Listener::die(const char *message){
    int err = errno;
    fprintf(stderr, "[%d] %s\n", err, message);
    abort();
}

// Start the listener
int TCP_Listener::start(){
    if(bind(this->fd, (const struct sockaddr *)&this->addr, sizeof(this->addr))==-1){
        die("Bind failed");
    }

    if(listen(this->fd, 1)==-1){
        die("Listen failed");
    }

    return this->fd;
}

// Close the listener
void TCP_Listener::close_listener(){
    if(this->fd!=-1){
        close(this->fd);
        this->fd = -1;
    }
}