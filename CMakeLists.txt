cmake_minimum_required(VERSION 3.20)
project(CMakeTest)

add_compile_options(-std=c++17 -Wall)

add_definitions(-DHBLJ_LOG)

# CMAKE_C_FLAGS = 
# CMAKE_C_FLAGS_DEBUG = -g
# CMAKE_C_FLAGS_MINSIZEREL = -Os -DNDEBUG
# CMAKE_C_FLAGS_RELEASE = -O3 -DNDEBUG
# CMAKE_C_FLAGS_RELWITHDEBINFO = -O2 -g -DNDEBUG
# CMAKE_CXX_FLAGS = 
# CMAKE_CXX_FLAGS_DEBUG = -g
# CMAKE_CXX_FLAGS_MINSIZEREL = -Os -DNDEBUG
# CMAKE_CXX_FLAGS_RELEASE = -O3 -DNDEBUG
# CMAKE_CXX_FLAGS_RELWITHDEBINFO = -O2 -g -DNDEBUG


set(HOME ${PROJECT_SOURCE_DIR})
set(OUTPUTPATH ${HOME}/bin)
set (OBJ_TMP ${OUTPUTPATH}/obj)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUTPATH})
set(LIBRARY_OUTPUT_PATH ${OUTPUTPATH})

include_directories(${HOME}/cpplib01)
include_directories(
    ${HOME}/cpplib02
    ${HOME}/cpplib03
    ${HOME}/cpplib04
)

add_subdirectory(cpplib01)
add_subdirectory(cpplib02)
add_subdirectory(cpplib03)
add_subdirectory(cpplib04)

aux_source_directory(${HOME} CPP_FILES)

link_directories(${OUTPUTPATH})
link_libraries(lib04)

add_executable(app01 ${CPP_FILES})
target_link_libraries(app01 lib03)
