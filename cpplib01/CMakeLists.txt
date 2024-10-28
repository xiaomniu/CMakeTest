cmake_minimum_required(VERSION 3.20)
project(cpplib01)

#[[
在CMake中可以用用户显示一条消息，该命令的名字为message
    message([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR] "message to display" ...)
        (无) ：重要消息
        STATUS ：非重要消息
        WARNING：CMake 警告, 会继续执行
        AUTHOR_WARNING：CMake 警告 (dev), 会继续执行
        SEND_ERROR：CMake 错误, 继续执行，但是会跳过生成的步骤
        FATAL_ERROR：CMake 错误, 终止所有处理过程

        CMake的命令行工具会在stdout上显示STATUS消息，在stderr上显示其他所有消息。CMake的GUI会在它的log区域显示所有消息。
        CMake警告和错误消息的文本显示使用的是一种简单的标记语言。文本没有缩进，超过长度的行会回卷，段落之间以新行做为分隔符
            # 输出一般日志信息
            message(STATUS "source path: ${PROJECT_SOURCE_DIR}")
            # 输出警告信息
            message(WARNING "source path: ${PROJECT_SOURCE_DIR}")
            # 输出错误信息
            message(FATAL_ERROR "source path: ${PROJECT_SOURCE_DIR}")
]]
message("++lib01 start++")
# set(LIBRARY_OUTPUT_PATH ${OUTPUTPATH})
message(STATUS ${LIBRARY_OUTPUT_PATH})

#[[
CMAKE_CURRENT_SOURCE_DIR 宏表示当前访问的 CMakeLists.txt 文件所在的路径
]]
set(NONCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
# file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SRC_LIST ${NONCE_DIR}/*.cpp)

#[[
在cmake中，如果要制作静态库，需要使用的命令如下：
    add_library(库名称 STATIC 源文件1 [源文件2] ...) 
    在Linux中，静态库名字分为三部分：lib+库名字+.a，此处只需要指定出库的名字就可以了，另外两部分在生成该文件的时候会自动填充

]]
add_library(lib01 STATIC ${SRC_LIST})
message("++lib01 end++")