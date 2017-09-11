#ifndef SHDOCUMENT_HANDLER_HPP
#define SHDOCUMENT_HANDLER_HPP

#include <experimental/filesystem>
#include <string>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include "../exception/Exception.hpp"

namespace nakhoadl {
    namespace Socket {
        namespace Handler {
            class File {
            public:
                /**
                 * Create new directory
                 *
                 * @param path
                 * @return `bool'
                 */
                bool createDir(const std::string &path);

                /**
                 * Create recursive directory
                 *
                 * @param path
                 * @return `bool'
                 */
                bool recursivelyCreateDir(const std::string &path);

                /**
                 * Get all filename in target directory
                 *
                 * @param path
                 * @return `std::vector<std::string>'
                 */
                static std::vector<std::string> getAllFileName(const std::string &pathToTargetDirectory);

                /**
                 * Get all contents in file
                 *
                 * @param filename
                 * @return `std::string*'
                 */
                static std::string *getContentFile(const std::string &filename);

                /**
                 * Split a std::string to vector, each element in vector
                 * contain a std::string* have 1024 character
                 *
                 * @param target
                 * @return `std::vector<std::string*>'
                 */
                static std::vector<std::string *> *splitStringToVector(const std::string &target);

                /**
                 * Get number of character in file
                 *
                 * @param filename
                 * @return `size_t'
                 */
                static size_t getSizeOfFile(const std::string &filename);

                /**
                 * Write std::string into new file,
                 * if file existed then all contents in this file are discarded
                 *
                 * @param target
                 * @param filename
                 * @return `bool'
                 */
                static bool writeStringToFile(const std::string *&target, const std::string &filename);

                /**
                 * Write st::vector<std::string> into new file,
                 * if file existed then all contents in this file are discarded
                 *
                 * @param target
                 * @param filename
                 * @return `bool'
                 */
                static bool
                writeVectorStringToFile(const std::vector<std::string *> *target, const std::string &filename);
            };


        } // Namespace Handler
    } // End of namespace Socket
} // End of namespace nakhoadl

#endif //SHDOCUMENT_HANDLER_HPP
