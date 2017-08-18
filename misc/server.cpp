#include "../src/server/Server.hpp"

int main() {
    nakhoadl::Server *server = nakhoadl::Server::getInstance();
    server->start();
}