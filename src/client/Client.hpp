#ifndef SHDOCUMENT_CLIENT_HPP
#define SHDOCUMENT_CLIENT_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../common/exception/Exception.hpp"
#include "../common/Common.hpp"

#define PORT 3000

namespace nakhoadl {
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

        void handl(Socket::SocketFileDescriptor socketFileDescriptor1);
    };
}



#endif //SHDOCUMENT_CLIENT_HPP
