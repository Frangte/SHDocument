#include "Exception.hpp"

using namespace nakhoadl;

Exception::Exception() {
    this->message = "[nakhoadl::Exception]";
}

Exception::Exception(std::string messageString) {
    this->message = messageString;
}

Exception::~Exception() {

}

string Exception::toString() const {
    return this->message.c_str();
}
