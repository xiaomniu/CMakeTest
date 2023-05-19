cmake_minimum_required(VERSION 3.20)
project(cpplib03)

message("++lib03 start++")
# set(LIBRARY_OUTPUT_PATH ${OUTPUTPATH})
message(STATUS ${LIBRARY_OUTPUT_PATH})

set(NONCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB SRC_LIST ${NONCE_DIR}/*.cpp)

link_directories(${OUTPUTPATH})
link_libraries(lib01)

add_library(lib03 SHARED ${SRC_LIST})
message("++lib03 end++")