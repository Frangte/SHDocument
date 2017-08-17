#include "../server/Server.hpp"

int main() {
    SHDocument::Server *server = SHDocument::Server::getInstance();
    server->start();
}