#include "Server.hpp"
#include "../exception/Exception.hpp"

using namespace SHDocument;

Server* Server::getInstance() {
    return Server::instance;
}

Server::Server() = default;

Server::~Server() = default;

void Server::createSocket() {
    if (socket(AF_INET, SOCK_STREAM, 0) < 0) {
        throw Exception("Can't create socket!!!");
    }
}

void Server::setSockopt(unsigned int port) {
    if (setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
               &this->opt, sizeof(this->opt))) {
        throw Exception("Setsockopt error!!!");
    }

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = (in_port_t ) htonl(port);
}

void Server::binding() {
    if (bind(this->server_fd, (struct sockaddr *)&address, this->addressLen) < 0) {
        throw Exception("Bind error!!!");
    }
}

void Server::listening() {
    if (listen(this->server_fd, 20) < 0) {
        throw Exception("Server can't listen!!!");
    }

    int newSocket_fd;
    
}