#include "../../src/common/handler/Handler.hpp"
#include "../../3rd party/catch/catch.hpp"

using namespace nakhoadl::Socket;

TEST_CASE("Handler") {
    SECTION("Get Contents File") {
        std::string *contentsFile = Handler::getContentFile("CMakeLists.txt");
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
                                        "TARGET_LINK_LIBRARIES(ClientRun ${CMAKE_THREAD_LIBS_INIT} stdc++fs)";
        CHECK(expectContents == *contentsFile);
        delete contentsFile;

        SECTION("No File To Open") {
            try {
                contentsFile = Handler::getContentFile("nofile.txt");
            } catch (Exception &exception) {
                std::string exceptionMessage = "Can't open file nofile.txt";
                CHECK(exceptionMessage == exception.toString());
            }
        } // Section "No File To Open"
    } // Section "Get Contents File"

    SECTION("Split string to vector") {
        SECTION("Empty string") {
            std::string stringToSplit;
            std::vector<std::string> *resultVector = Handler::splitStringToVector(stringToSplit);



            delete resultVector;
        } // Section Empty String

        SECTION("Length of string is multiples of 1024") {
            std::string stringToSplit(1027, 'a');
            std::vector<std::string> *resultVector = Handler::splitStringToVector(stringToSplit);



            delete resultVector;
        } // Section Length of string is multiples of 1024

        SECTION("Normal string") {
            
        }
    }
}
