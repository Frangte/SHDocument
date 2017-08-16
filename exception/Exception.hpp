#ifndef SHDOCUMENT_EXCEPTION_HPP
#define SHDOCUMENT_EXCEPTION_HPP

#include <string>
#include <iostream>

namespace SHDocument {
    class Exception : public std::exception {
    private:
        std::string message;

    public:
        Exception(std::string message);
        ~Exception();
        friend std::ostream &operator<< (std::ostream &os, const Exception &target);
    };
}

#endif //SHDOCUMENT_EXCEPTION_HPP
