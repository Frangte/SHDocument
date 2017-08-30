#ifndef SHDOCUMENT_HANDLER_HPP
#define SHDOCUMENT_HANDLER_HPP

#include <experimental/filesystem>
#include <string>
#include <vector>
#include "../exception/Exception.hpp"

namespace nakhoadl {
    namespace Socket {
        class Handler {
        private:
            typedef enum {
                EXITS,
                NOT_EXIST,
                FORGOT_PASSWORD
            } checker;

        public:
            /**
             * Get all filenames in target directory
             *
             * @param path
             * @return `std::vector<std::string>'
             */
            static std::vector<std::string> getAllFileName(const std::string pathToTargetDirectory);

            /**
             * Check whether user exist or not
             *
             * @param username
             * @param password
             * @return `checker'
             */
            static checker checkUser(const std::string username, const std::string password);
         };
    } // End of namespace Socket
} // End of namespace nakhoadl

#endif //SHDOCUMENT_HANDLER_HPP
