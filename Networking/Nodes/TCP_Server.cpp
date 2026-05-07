#include "TCP_Server.hpp"


TCP_Server::TCP_Server(int port, int saddr, int qsize) : listener(port, saddr, qsize), queue_size(qsize) {}

TCP_Server::~TCP_Server() {
    // Cleanup if necessary
    stop();
}

int TCP_Server::get_queue_size() {
    return queue_size;
}

void TCP_Server::start() {
    listener.start();

    while (true) {
        int client_fd = accept_client();
        if (client_fd < 0) {
            continue; // Accept failed, try again
        }

        std::string message = read_from_client(client_fd);
        std::cout << "Received from client: " << message << std::endl;

        write_to_client(client_fd, "Message received!");
        close_client(client_fd);

        if (message == "shutdown") {
            break; // Exit the loop to stop the server
        }
        // client_fds.push_back(client_fd);
        // Handle the new client connection as needed
    }
    stop();
    // std::cout << "Server started and listening on port " << ntohs(listener.get_addr().sin_port) << std::endl;
}

void TCP_Server::stop() {
    listener.close_listener();
    // Close all client connections
    for (int fd : client_fds) {
        close(fd);
    }
    client_fds.clear();
}

int TCP_Server::accept_client() {
    int client_fd = listener.accept_connection();
    // if (client_fd >= 0) {
    //     client_fds.push_back(client_fd);
    // }
    return client_fd;
}

void TCP_Server::close_client(int client_fd) {
    close(client_fd);
    // client_fds.erase(std::remove(client_fds.begin(), client_fds.end(), client_fd), client_fds.end());
}

void TCP_Server::write_to_client(int client_fd, const std::string &message) {
    write(client_fd, message.c_str(), message.size());
}

std::string TCP_Server::read_from_client(int client_fd) {
    char buffer[1024];
    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        return std::string(buffer);
    }
    return "";
}