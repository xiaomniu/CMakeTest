cmake_minimum_required(VERSION 3.20)
project(cpplib02)

message("++lib02 start++")
# set(LIBRARY_OUTPUT_PATH ${OUTPUTPATH})
message(STATUS ${LIBRARY_OUTPUT_PATH})

set(NONCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
# file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SRC_LIST ${NONCE_DIR}/*.cpp)

#[[
在cmake中，如果要制作动态库，需要使用的命令如下：
    add_library(库名称 SHARED 源文件1 [源文件2] ...) 
    在Linux中，动态库名字分为三部分：lib+库名字+.so，此处只需要指定出库的名字就可以了，另外两部分在生成该文件的时候会自动填充

]]
add_library(lib02 SHARED ${SRC_LIST})
message("++lib02 end++")