#include <unistd.h>
#include "Client.hpp"
#include "../server/Server.hpp"

using namespace nakhoadl;

Client* Client::instance = nullptr;

Client::Client() {
    this->createClient();
    this->connect();
}

Client& Client::createClient() {
    if ((this->socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        Exception exception("Can't create socket.");
        throw exception;
    }

    std::cout << "Create socket successfully." << std::endl;
    return *this;
}

Client& Client::connect() {
    sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    if ((inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr)) <= 0) {
        Exception exception("Invalid address, Address not supported.");
        throw exception;
    }

    if (::connect(this->socketFileDescriptor, (sockaddr *)&serverAddress,
                  sizeof(serverAddress)) < 0) {
        std::cout << "Can't connect." << std::endl;
        exit(1);
    }

    std::cout << "Connect successfully." << std::endl;
    this->handl(this->socketFileDescriptor);
}

void Client::close() {
    ::close(this->socketFileDescriptor);
    delete Client::instance;
    Client::instance = nullptr;
}

Client* Client::getInstance() {
    if (Client::instance == nullptr) {
        Client::instance = new Client();
    }

    return Client::instance;
}

void Client::handl(SocketFileDescriptor socketFileDescriptor) {
    bool running = true;
    while (running) {
        std::string request;
        std::cout << "Please typing: ";
        getline(std::cin, request);
        send(socketFileDescriptor, request.c_str(),  request.size(), 0);
        std::cout << "Number of request: " << request.size() << std::endl;
        if (request == "end") {
            break;
        }
    }
    ::close(socketFileDescriptor);
}
