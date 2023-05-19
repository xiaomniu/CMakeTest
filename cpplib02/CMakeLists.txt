cmake_minimum_required(VERSION 3.20)
project(cpplib02)

message("++lib02 start++")
# set(LIBRARY_OUTPUT_PATH ${OUTPUTPATH})
message(STATUS ${LIBRARY_OUTPUT_PATH})

set(NONCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
# file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SRC_LIST ${NONCE_DIR}/*.cpp)

add_library(lib02 SHARED ${SRC_LIST})
message("++lib02 end++")