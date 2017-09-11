#include "../../src/common/handler/Handler.hpp"
#include "../../3rd party/catch/catch.hpp"

using namespace nakhoadl::Socket;
using namespace nakhoadl::Socket::Handler;

TEST_CASE("Handler") {
    SECTION("Get Contents File") {
        std::string *contentsFile = File::getContentFile("misc/filetotest/CMakeLists.txt");
        std::string expectContents =    "CMAKE_MINIMUM_REQUIRED(VERSION 3.2)\n"
                                        "PROJECT(SHDocument C CXX)\n"
                                        "\n"
                                        "FILE(GLOB_RECURSE Handler\n"
                                        "                  src/common/handler/*.cpp)\n"
                                        "\n"
                                        "FILE(GLOB_RECURSE Client\n"
                                        "                  src/client/*.cpp)\n"
                                        "\n"
                                        "FILE(GLOB_RECURSE Test\n"
                                        "                  test/**/*.cpp)\n"
                                        "\n"
                                        "FILE(GLOB_RECURSE Server\n"
                                        "                  src/server/*.cpp)\n"
                                        "\n"
                                        "FILE(GLOB_RECURSE Json\n"
                                        "                  src/3rd\n"
                                        "                  party/json/*.hpp)\n"
                                        "\n"
                                        "FILE(GLOB_RECURSE Exception\n"
                                        "                  src/common/exception/*.cpp)\n"
                                        "\n"
                                        "# Find pthread\n"
                                        "FIND_PACKAGE(Threads REQUIRED)\n"
                                        "\n"
                                        "ADD_COMPILE_OPTIONS(-std=gnu++17)\n"
                                        "\n"
                                        "ADD_EXECUTABLE(ServerRun ${Server} ${Handler} ${Exception} misc/server.cpp)\n"
                                        "ADD_EXECUTABLE(ClientRun ${Client} ${Handler} ${Exception} misc/client.cpp)\n"
                                        "ADD_EXECUTABLE(AllTest ${Test} ${Handler} ${Exception} misc/mainTest.cpp)\n"
                                        "\n"
                                        "# Link target Server_run to lib pthread\n"
                                        "TARGET_LINK_LIBRARIES(ServerRun ${CMAKE_THREAD_LIBS_INIT} stdc++fs)\n"
                                        "TARGET_LINK_LIBRARIES(AllTest stdc++fs)\n"
                                        "TARGET_LINK_LIBRARIES(ClientRun ${CMAKE_THREAD_LIBS_INIT} stdc++fs)\n"
                                        "\n"
                                        "ADD_CUSTOM_TARGET(check-leak-test\n"
                                        "                  COMMAND valgrind --tool=memcheck --leak-check=yes ./AllTest)";
        CHECK(expectContents == *contentsFile);
        delete contentsFile;

        SECTION("No File To Open") {
            try {
                contentsFile = File::getContentFile("nofile.txt");
            } catch (Exception &exception) {
                std::string exceptionMessage = "Can't open file nofile.txt";
                CHECK(exceptionMessage == exception.toString());
            }
        } // Section "No File To Open"
    } // Section "Get Contents File"

    SECTION("Get Size File") {
        SECTION("No file to open") {
            size_t sizeOfFile = File::getSizeOfFile("misc/filetotest/nofile.txt");
            CHECK(0 == sizeOfFile);
        } // Section No file to open

        SECTION("Empty file") {
            size_t sizeOfFile = File::getSizeOfFile("misc/filetotest/emptyfile.txt");
            CHECK(0 == sizeOfFile);
        } // Section Empty file

        SECTION("Normal file") {
            size_t sizeOfFile = File::getSizeOfFile("misc/filetotest/filetotest.txt");
            CHECK(75436 == sizeOfFile);
        } // Section Normal file
    }

    SECTION("Split String To Vector") {
        SECTION("Empty string") {
            std::string stringToSplit;
            std::vector<std::string*> *resultVector = File::splitStringToVector(stringToSplit);
            delete resultVector;
        } // Section Empty String

        SECTION("Length of string is multiples of 1024") {
            std::string stringToSplit(2048, 'a');
            std::vector<std::string*> *resultVector = File::splitStringToVector(stringToSplit);

            std::string expectOfEachElement(1024, 'a');
            CHECK(expectOfEachElement == (*(*resultVector)[0]));
            CHECK(expectOfEachElement == (*(*resultVector)[1]));

            size_t sizeOfVector = resultVector->size();
            CHECK(sizeOfVector == 2);

            size_t index;
            for (index = 0; index < resultVector->size(); index++) {
                delete (*resultVector)[index];
            }
            delete resultVector;
        } // Section Length of string is multiples of 1024

        SECTION("Normal string") {
            std::string *stringToSplit = File::getContentFile("misc/filetotest/filetotest.txt");
            std::vector<std::string*> *vectorContent = File::splitStringToVector(*stringToSplit);

            size_t expectSizeOfVector = 74;
            CHECK(expectSizeOfVector == vectorContent->size());
            size_t index;
            for (index = 0; index < vectorContent->size(); index++) {
                delete (*vectorContent)[index];
            }
            delete vectorContent;
            delete stringToSplit;
        } // Section Normal string
    } // Section split string to vector

    SECTION("General inspection") {
        std::string *stringReadFromExistFile;
        try {
            stringReadFromExistFile = File::getContentFile("misc/filetotest/filetotest.txt");
        } catch (Exception &exception) {
            std::cout << exception << std::endl;
        }

        // Split a string
        std::vector<std::string*> *contentsFile = File::splitStringToVector(*stringReadFromExistFile);

        // Write vector<string> into vector then get contents this file to compare with stringReadFromExistFile
        bool resultWriteFile = File::writeVectorStringToFile(contentsFile, "misc/filetotest/newfile.txt");
        CHECK(resultWriteFile);

        // Read newFile.txt to string then compare
        std::string *contentsOfNewFile = File::getContentFile("misc/filetotest/newfile.txt");
        CHECK(*stringReadFromExistFile == *contentsOfNewFile);

        size_t index;
        for (index = 0; index < contentsFile->size(); index++) {
            delete (*contentsFile)[index];
        }
        delete contentsOfNewFile;
        delete contentsFile;
        delete stringReadFromExistFile;
    } // Section general inspection
} // Section Handler
