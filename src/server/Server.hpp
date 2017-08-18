#ifndef SHDOCUMENT_SERVER_HPP
#define SHDOCUMENT_SERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

namespace nakhoadl {
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

        /**
         * Create socket
         *
         * @return `Server &'
         */
        Server &createSocket();

        /**
         * Set Socopt
         *
         * @param port `unsigned int'
         * @return `Server &'
         */
        Server &setSockopt(unsigned int port);

        /**
         * Bind socket
         *
         * @return `Server &'
         */
        Server &binding();

    public:
        /**
         * Get instance of class
         *
         * @return Server*
         */
        static Server *getInstance();

        /**
         * Socket start listen
         */
        void start();
    };
}


#endif //SHDOCUMENT_SERVER_HPP
