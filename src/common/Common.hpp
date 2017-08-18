#ifndef SHDOCUMENT_COMMON_HPP
#define SHDOCUMENT_COMMON_HPP

#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include "message/Massage.hpp"

typedef char* string;

namespace nakhoadl {
    namespace Socket {
        typedef int SocketFileDescriptor;
        typedef std::string Ip;
        typedef unsigned int Port;

        typedef struct {
            Ip ip;
            Port port;
        } Address;

        typedef struct {
            Address address;
            Message message;
        } Datagram;
    }
}

#endif //SHDOCUMENT_COMMON_HPP
