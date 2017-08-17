#ifndef SHDOCUMENT_CLIENT_HPP
#define SHDOCUMENT_CLIENT_HPP
#include "../json/json.hpp"

namespace SHDocument {
    class Client {
    private:
        static Client *instance;

        Client();
    };
}



#endif //SHDOCUMENT_CLIENT_HPP
