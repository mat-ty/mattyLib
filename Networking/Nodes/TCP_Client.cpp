#include "TCP_Client.hpp"

TCP_Client::TCP_Client() : connection() {}

TCP_Client::TCP_Client(int port, int saddr) : connection(port, saddr) {}

TCP_Client::~TCP_Client() {
    close_client();
}

int TCP_Client::connect_to_server() {
    return connection.connect_to_host();
}

void TCP_Client::close_client() {
    connection.close_connection();
}

void TCP_Client::write_to_server(const std::string &message) {
    ssize_t bytes_sent = write(connection.get_fd(), message.c_str(), message.size());
    if (bytes_sent < 0) {
        perror("Failed to send message to server");
    }
}

std::string TCP_Client::read_from_server() {
    char buffer[1024];
    ssize_t bytes_read = read(connection.get_fd(), buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Failed to read message from server");
        return "";
    }
    buffer[bytes_read] = '\0'; // Null-terminate the buffer
    return std::string(buffer);
}