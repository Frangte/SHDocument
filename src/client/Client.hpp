#ifndef SHDOCUMENT_CLIENT_HPP
#define SHDOCUMENT_CLIENT_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../common/exception/Exception.hpp"

#define PORT 3000

namespace nakhoadl {
    namespace Socket {
        class Client {
        private:
            static Client *instance;

            Socket::SocketFileDescriptor socketFileDescriptor;

            Client();

            Client &createClient();

            Client &connect();
        public:
            static Client *getInstance();

            void close();

            void handle(Socket::SocketFileDescriptor socketFileDescriptor1);
        };
    } // End of namespace Socket
} // End of namespace ankhoadl

#endif //SHDOCUMENT_CLIENT_HPP
