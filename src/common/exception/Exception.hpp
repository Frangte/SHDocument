#ifndef SHDOCUMENT_EXCEPTION_HPP
#define SHDOCUMENT_EXCEPTION_HPP

#include "../common.hpp"
#include <string>
#include <iostream>

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
            os << this->message << std::endl;
            return os;
        }
    };

    class RuntimeException : public Exception {
    public:
        RuntimeException() : Exception() {

        }

        RuntimeException(std::string messageString) : Exception(messageString) {

        }

        ~RuntimeException() {

        }

        /**
         * Implement operator output of object RuntimeException
         *
         * @param os `std::ostream &'
         * @param exception `RuntimeException &'
         * @return `std::ostream &'
         */
        friend std::ostream &operator<<(std::ostream &os, const RuntimeException &exception) {
            os << this->message << std::endl;
            return os;
        }
    };
}

#endif //SHDOCUMENT_EXCEPTION_HPP
