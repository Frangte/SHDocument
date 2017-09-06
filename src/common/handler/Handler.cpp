#include <unistd.h>
#include "Handler.hpp"

using namespace nakhoadl::Socket;
namespace fs = std::experimental::filesystem;

std::vector<std::string> Handler::getAllFileName(const std::string pathToTargetDirectory) {
    std::vector<std::string> resultVector;
    try {
        for (auto &p : fs::directory_iterator(pathToTargetDirectory)) {
            resultVector.push_back(p.path().c_str());
        }
    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
    }

    return resultVector;
}

bool Handler::createDir(const std::string &path) {
    return mkdir(path.c_str(),  S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

bool Handler::recursivelyCreateDir(const std::string &path) {
    if (createDir(path)) return true;

    if (access(path.c_str(), F_OK) == 0) return false; // Exists path in this directory

    size_t slashPos = path.find_last_of('/');
    if (slashPos == std::string::npos) return false;

    return recursivelyCreateDir(path.substr(0, slashPos));
}
