CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(SHDocument)

FILE(GLOB_RECURSE Handler handler/*)
FILE(GLOB_RECURSE Client client/*)
FILE(GLOB_RECURSE Test test/*)
FILE(GLOB_RECURSE Server server/*)
FILE(GLOB_RECURSE Json json/*)

ADD_CUSTOM_TARGET(server ${Server} ${Json})
ADD_CUSTOM_TARGET(client ${Client} ${Json})
ADD_CUSTOM_TARGET(all_test &{Test})
