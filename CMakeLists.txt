CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(SHDocument)

FILE(GLOB_RECURSE Handler handler/*.cpp)
FILE(GLOB_RECURSE Client client/*.cpp)
FILE(GLOB_RECURSE Test test/*.cpp)
FILE(GLOB_RECURSE Server server/*.cpp)
FILE(GLOB_RECURSE Json json/*.hpp)

ADD_EXECUTABLE(server_run ${Server} ${Handler} misc/server.cpp)
ADD_EXECUTABLE(client_run ${Client} ${Handler} misc/client.cpp)
