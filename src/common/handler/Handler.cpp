#include <unistd.h>
#include "Handler.hpp"

using namespace nakhoadl::Socket;
namespace fs = std::experimental::filesystem;

std::vector<std::string> Handler::getAllFileName(const std::string &pathToTargetDirectory) {
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

std::string *Handler::getContentFile(const std::string &filename) {
    std::ifstream fileIn(filename.c_str(), std::ios::binary);

    if (!fileIn.is_open()) {
        throw Exception("Can't open file " + filename);
    }

    auto *contentsFile = new std::string();
    fileIn.seekg(0, std::ios::end);
    contentsFile->resize((unsigned long)fileIn.tellg());
    fileIn.seekg(0, std::ios::beg);

    fileIn.read(&(*contentsFile)[0], contentsFile->size());
    fileIn.close();
    return contentsFile;
}

std::vector<std::string*>* Handler::splitStringToVector(const std::string &target) {
    // Get size of vector
    std::vector<std::string*> *resultVector = new std::vector<std::string*>();
    size_t sizeOfVector = target.size() / 1024;
    if (target.size() % 1024 > 0) {
        sizeOfVector += 1;
    }

    if (sizeOfVector == 0) {
        return resultVector;
    }

    size_t index;
    size_t indexInString = 0;
    for (index = 0; index < sizeOfVector - 1; index++) {
        auto *bufferString = new std::string;
        bufferString->resize(1025);
        *bufferString = target.substr(indexInString, 1024);
        resultVector->push_back(bufferString);
        indexInString += 1024;
    }
    auto *endOfString = new std::string;
    *endOfString = target.substr((unsigned long)indexInString, target.size() - indexInString);
    endOfString->shrink_to_fit();
    resultVector->push_back(endOfString);
    return resultVector;
}

size_t Handler::getSizeOfFile(const std::string &filename) {
    std::fstream infile(filename.c_str());

    if (!infile.is_open()) {
        return 0;
    }

    infile.seekg(0, std::ios::end);
    size_t sizeResult = (size_t) infile.tellg();
    infile.seekg(0, std::ios::beg);
    infile.close();
    return sizeResult;
}

bool Handler::writeStringToFile(const std::string *&target, const std::string &filename) {
    std::ofstream fileToWrite(filename.c_str(), std::ios::trunc);

    if (!fileToWrite.is_open()) {
        return false;
    }

    fileToWrite.write( &(*target)[0], target->size());
    fileToWrite.close();
    return true;
}


bool Handler::writeVectorStringToFile(const std::vector<std::string *> *target, const std::string &filename) {
    std::ofstream fileToWrite(filename.c_str(), std::ios::trunc);

    if (!fileToWrite.is_open()) {
        return false;
    }

    size_t index;
    for (index = 0; index < target->size(); index++) {
        fileToWrite.write(&(*((*target)[index]))[0], (*target)[index]->size()); // Wtf &(*((*target)[index]))[0]
    }
    fileToWrite.close();
    return true;
}
