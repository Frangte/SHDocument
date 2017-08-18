#ifndef SHDOCUMENT_EXCEPTION_HPP
#define SHDOCUMENT_EXCEPTION_HPP

#include "../Common.hpp"
#include <string>
#include <iostream>
#include <exception>

namespace nakhoadl {
    class Exception {
    private:
        std::string message;

    public:
        /**
         * Exception constructor
         */
        Exception();

        /**
         * Exception copy constructor
         *
         * @param exception
         */
        Exception(const Exception &exception);

        /**
         * Exception constructor with `const char'
         *
         * @param message
         */
        Exception(const char *message);

        /**
         * Exception constructor with `std::string'
         */
        Exception(std::string messageString);

        /**
         * Exception destructor
         */
        virtual ~Exception();

        /**
         * Get message of Exception
         *
         * @return `string'
         */
        string toString() const;

        /**
         * Implement operator output of object Exception
         *
         * @param os `std::ostream &'
         * @param exception `Exception &'
         * @return `std::ostream &'
         */
        friend std::ostream &operator<<(std::ostream &os, const Exception &exception) {
            os << exception.toString() << std::endl;
            return os;
        }
    };
}

#endif //SHDOCUMENT_EXCEPTION_HPP
