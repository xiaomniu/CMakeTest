cmake_minimum_required(VERSION 3.20)
project(cpplib04)

message("++lib04 start++")
set(NONCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB SRC_LIST ${NONCE_DIR}/*.cpp)

# include_directories(${HOME}/cpplib01)
# include_directories(
#     ${HOME}/cpplib02
#     ${HOME}/cpplib03
#     ${HOME}/cpplib04
# )

# set(LIBRARY_OUTPUT_PATH ${OUTPUTPATH})
message(STATUS ${LIBRARY_OUTPUT_PATH})

link_directories(${OUTPUTPATH})
link_libraries(lib02)

add_library(lib04 STATIC ${SRC_LIST})
# target_link_libraries(lib04 pthread zlib gdal)
target_link_libraries(lib04 lib02)
message("++lib04 end++")