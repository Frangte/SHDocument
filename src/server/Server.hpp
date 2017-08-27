#ifndef SHDOCUMENT_SERVER_HPP
#define SHDOCUMENT_SERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> // for close
#include <iostream>
#include <thread> // for std::thread
#include <functional> // for std::ref
#include <cstring> // for std::memset
#include "../common/Common.hpp"
#include "../common/exception/Exception.hpp"

#define PORT 3000

namespace nakhoadl {
    namespace Socket {


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
             * This function is handle request of client and make a response to them
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
    } // End of namespace Socket
} // End of namespace nakhoadl


#endif //SHDOCUMENT_SERVER_HPP
