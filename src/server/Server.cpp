#include <stdexcept>
#include <unistd.h>
#include "Server.hpp"

using namespace nakhoadl;

Server* Server::instance = NULL;

Server* Server::getInstance() {
    if (Server::instance == nullptr) {
        Server::instance = new Server();
    }

    return Server::instance;
}

Server::Server() {
    createSocket().
    setSockopt(3000).
    binding();
}

Server::~Server() = default;

Server &Server::createSocket() {
    if ((this->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        throw std::runtime_error("Can not create socket.");
    }

    std::cout << "Successfully created server." << std::endl;
    return *this;
}
Server &Server::setSockopt(unsigned int port) {
    if (setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
               &this->opt, sizeof(this->opt))) {
        throw std::runtime_error("Setsockopt error.");
    }

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(port);

    std::cout << "Successfully setsockopt and run at port " << port << "." << std::endl;
    return *this;
}

Server &Server::binding() {
    if (bind(this->server_fd, (struct sockaddr*)&this->address, this->addressLen) < 0) {
        throw std::runtime_error("Bind error.");
    }

    std::cout << "Successfully binding." << std::endl;
    return *this;
}

void Server::start() {
    if (listen(this->server_fd, 20) < 0) {
        throw std::runtime_error("Listen error");
    }

    std::cout << "Server: waiting for connection." << std::endl;
    int newSocket_fd;
    struct sockaddr_storage clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);
    while (true) {
        if ((newSocket_fd = accept(server_fd, (struct sockaddr *)&clientAddress,
                                   (socklen_t*)&clientAddressLen)) < 0) {
            throw std::runtime_error("Server can't accept connection.");
        }

        char ipClient[INET_ADDRSTRLEN];
        inet_ntop(clientAddress.ss_family, &((struct sockaddr_in *) &clientAddress)->sin_addr, ipClient,
                  INET_ADDRSTRLEN);
        std::cout << "Server got connection from: " << ipClient << "." << std::endl;
    }
}
