#include "Exception.hpp"

using namespace nakhoadl::Socket;

Exception::Exception() {
    this->message = "[nakhoadl::Exception]";
}

Exception::Exception(const Exception &exception) {
    this->message = exception.message;
}

Exception::Exception(const std::string &messageString) {
    this->message = messageString;
}

Exception::Exception(const char *message) {
    this->message = message;
}

Exception::~Exception() = default;

string Exception::toString() const {
    return (string) this->message.c_str();
}
