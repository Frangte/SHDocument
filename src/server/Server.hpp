#ifndef SHDOCUMENT_SERVER_HPP
#define SHDOCUMENT_SERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <thread>
#include <functional>
#include <cstring>
#include <mutex>
#include "../common/Common.hpp"
#include "../common/exception/Exception.hpp"

#define PORT 3000

namespace nakhoadl {
    using namespace Socket;
    class Server {
    private:
        SocketFileDescriptor socketFileDescriptor;
        static unsigned int countClient;

        /**
         * Static instance of class
         */
        static Server *instance;

        /**
         * Server constructor
         */
        Server();

        /**
         * Server destructor
         */
        ~Server();

        /**
         * Delete instance Server
         */
        void destroyServer();

        /**
         * Create socket
         *
         * @return `Server &'
         */
        Server &createSocket();

        /**
         * Bind socket
         *
         * @return `Server &'
         */
        Server &binding();

        /**
         * This function is handle request of client and response to them
         */
        void handle(SocketFileDescriptor socketFileDescriptor);

    public:
        /**
         * Get instance of class
         *
         * @return Server*
         */
        static Server *getInstance();

        /**
         * Run server
         */
        void start();
    };
}


#endif //SHDOCUMENT_SERVER_HPP
