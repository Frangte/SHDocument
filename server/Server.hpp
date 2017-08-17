#ifndef SHDOCUMENT_SERVER_HPP
#define SHDOCUMENT_SERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <iostream>

namespace SHDocument {
    class Server {
    private:
        int server_fd;
        struct sockaddr_in address;
        int opt = 1;
        socklen_t addressLen = sizeof(Server::address);
        /**
         * Server constructor
         */
        Server();

        /**
         * Server destructor
         */
        ~Server();

        /**
         * Static instance of class
         */
        static Server *instance;

        void createSocket();

        void setSockopt(unsigned int port);

        void binding();

        void listening();

       // void handl();

    public:
        /**
         * Get instance of class
         *
         * @return Server*
         */
        static Server *getInstance();

        void start();
    };
}


#endif //SHDOCUMENT_SERVER_HPP
