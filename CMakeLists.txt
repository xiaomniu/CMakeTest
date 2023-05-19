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

# 这里CMAKE_C_FLAGS_DEBUG默认只是有一个“-g”，所以，可以在此基础上添加优化选项
# set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
# set(CMAKE_C_FLAGS_Release "${CMAKE_C_FLAGS_Release} -O3")

# 分别设置CMAKE_CXX_FLAGS_DEBUG和CMAKE_CXX_FLAGS_RELEASE
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -Wl,-rpath=../lib")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -g")

# 上面的设置两个都有-std=c++11，这个选项是一个公共的选项，不管是Release还是Debug都需要设置。
# 这种情况还可以把公共的设置放在CMAKE_CXX_FLAGS变量里面
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -Wl,-rpath=../lib")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g")


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
