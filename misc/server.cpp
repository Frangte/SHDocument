#include "../src/server/Server.hpp"

using namespace nakhoadl::Socket;

int main() {
    Server *server = Server::getInstance();
    server->start();
}