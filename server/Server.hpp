#ifndef SHDOCUMENT_SERVER_HPP
#define SHDOCUMENT_SERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>

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
        static Server *instance = new Server();

    public:
        /**
         * Get instance of class
         *
         * @return Server*
         */
        static Server *getInstance();

        /**
         * Get port of Server
         *
         * @return unsigned int
         */
        unsigned int getPort() const;

        void createSocket();

        void setSockopt(unsigned int port);

        void binding();

        void listening();

        void handl();

        void start();
    };
}


#endif //SHDOCUMENT_SERVER_HPP
