#ifndef SHDOCUMENT_CLIENT_HPP
#define SHDOCUMENT_CLIENT_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../3rd party/json/json.hpp"

namespace nakhoadl {
    class Client {
    private:
        struct sockaddr_in clientAddress;

        static Client *instance;

        Client();

    public:
        static Client *getInstance();


    };
}



#endif //SHDOCUMENT_CLIENT_HPP
