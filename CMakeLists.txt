CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(SHDocument)

FILE(GLOB_RECURSE Handler src/handler/*.cpp)
FILE(GLOB_RECURSE Client src/client/*.cpp)
FILE(GLOB_RECURSE Test test/*.cpp)
FILE(GLOB_RECURSE Server src/server/*.cpp)
FILE(GLOB_RECURSE Json "src/3rd party/json/*.hpp")

ADD_COMPILE_OPTIONS(-std=gnu++11)

ADD_EXECUTABLE(Server_run ${Server} ${Handler} misc/server.cpp)
ADD_EXECUTABLE(Client_run ${Client} ${Handler} misc/client.cpp)
