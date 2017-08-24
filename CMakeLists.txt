CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(SHDocument C CXX)

FILE(GLOB_RECURSE Handler
        src/handler/*.cpp)

FILE(GLOB_RECURSE Client
                  src/client/*.cpp)

FILE(GLOB_RECURSE Test
                  test/*.cpp)

FILE(GLOB_RECURSE Server
        src/server/*.cpp)

FILE(GLOB_RECURSE Json
                  src/3rd
                  party/json/*.hpp)

FILE(GLOB_RECURSE Exception
                  src/common/exception/*.cpp)

# Find pthread
FIND_PACKAGE(Threads REQUIRED)

ADD_COMPILE_OPTIONS(-std=gnu++11)

ADD_EXECUTABLE(Server_run ${Server} ${Handler} ${Exception} misc/server.cpp)
ADD_EXECUTABLE(Client_run ${Client} ${Handler} ${Exception} misc/client.cpp)

TARGET_LINK_LIBRARIES (Server_run ${CMAKE_THREAD_LIBS_INIT})