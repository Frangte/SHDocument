CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(SHDocument C CXX)

FILE(GLOB_RECURSE Handler
        src/common/handler/*.cpp)

FILE(GLOB_RECURSE Client
                  src/client/*.cpp)

FILE(GLOB_RECURSE Test
                  misc/mainTest.cpp
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


ADD_EXECUTABLE(ServerRun ${Server} ${Handler} ${Exception} misc/server.cpp)
ADD_EXECUTABLE(ClientRun ${Client} ${Handler} ${Exception} misc/client.cpp)
ADD_EXECUTABLE(AllTest ${Test})
# Link target Server_run to lib pthread
TARGET_LINK_LIBRARIES (ServerRun ${CMAKE_THREAD_LIBS_INIT})