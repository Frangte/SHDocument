#include "Handler.hpp"

using namespace nakhoadl::Socket;
namespace fs = std::experimental::filesystem;

std::vector<std::string> Handler::getAllFileName(const std::string pathToTargetDirectory) {
    std::vector<std::string> resultVector;
    std::string filename;
    try {
        for (filename : fs::directory_iterator(".")) {
            std::cout << filename << std::endl;
        }
    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
    }

    return resultVector;
}
