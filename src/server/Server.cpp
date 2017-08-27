#include "Server.hpp"

using namespace nakhoadl::Socket;

Server* Server::instance = nullptr;
unsigned int Server::countClient = 0;

Server* Server::getInstance() {
    if (Server::instance == nullptr) {
        Server::instance = new Server();
    }
    return Server::instance;
}

Server::Server() {
    createSocket();
    binding();
}

Server::~Server() = default;

void Server::destroyServer() {
    if (Server::instance != nullptr) {
        delete Server::instance;
    }
    Server::instance = nullptr;
}

Server &Server::createSocket() {
    if ((this->socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        throw Exception("Can not create socket.");
    }
    return *this;
}

Server &Server::binding() {
    sockaddr_in serverAddress;

    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    int enable = 1;
    if (setsockopt(this->socketFileDescriptor,
                   SOL_SOCKET, (SO_REUSEPORT | SO_REUSEADDR),
                   &enable, sizeof(enable)) < 0)
    {
        Exception message("Error setsockopt.");
        throw message;
    }


    if (bind(this->socketFileDescriptor, (struct sockaddr*)&serverAddress,
                                               sizeof(serverAddress)) < 0)
    {
        Exception message("Bind error.");
        throw message;
    }

    std::cout << "Successfully bind and server run at port " << PORT << "." << std::endl;
    return *this;
}

void Server::handle(SocketFileDescriptor socketFileDescriptor) {
    char request[100];
    while (true) {
        std::memset(request, 0, 100);
        ssize_t bytes = recv(socketFileDescriptor, request, 100, 0); // Receives request from connected socket
        if (bytes == 0) {
            break;
        }

        std::cout << "Thread id: " << std::this_thread::get_id()
                  << ", Client: "  << socketFileDescriptor
                  << ", Bytes = "  << bytes
                  << ", Message: " << request << std::endl;

    }
    ::close(socketFileDescriptor);
    Server::countClient--;
    std::cout << "Client " << socketFileDescriptor << " disconnected"
              << ", number of client: " << Server::countClient << ".\n";
}

void Server::start() {
    if (listen(this->socketFileDescriptor, 20) < 0) {
        throw Exception("Listen error.");
    }

    std::cout << "Server waiting for connection." << std::endl;
    struct sockaddr_storage clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);
    while (true) {
        SocketFileDescriptor newSocketFileDescriptor;
        if ((newSocketFileDescriptor = accept(socketFileDescriptor,
                                             (struct sockaddr *)&clientAddress,
                                             &clientAddressLen)) < 0)
        {
            throw Exception("Server can't accept connection.");
        }

        Server::countClient++;
        char ipClient[INET_ADDRSTRLEN];
        inet_ntop(clientAddress.ss_family, &((struct sockaddr_in *)&clientAddress)->sin_addr,
                                                                  ipClient, INET_ADDRSTRLEN);

        std::cout << "Server got connection from: " << ipClient
                  << ", number of client: " << Server::countClient
                  << std::endl;

        std::thread newThread(&Server::handle, this, std::ref(newSocketFileDescriptor));
        newThread.detach();
    }
}
