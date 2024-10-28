
# cmake_minimum_required：指定使用的 cmake 的最低版本
cmake_minimum_required(VERSION 3.20)
# project：定义工程名称，并可指定工程的版本、工程描述、web主页地址、支持的语言（默认情况支持所有语言），如果不需要这些都是可以忽略的，只需要指定出工程名字即可。
#[[
# PROJECT 指令的语法是：
project(<PROJECT-NAME> [<language-name>...])
project(<PROJECT-NAME>
       [VERSION <major>[.<minor>[.<patch>[.<tweak>] ] ] ]
       [DESCRIPTION <project-description-string>]
       [HOMEPAGE_URL <url-string>]
       [LANGUAGES <language-name>...])
]]
project(CMakeTest)

add_compile_options(-std=c++17 -Wall)

#[[
在gcc/g++命令中通过参数 -D指定出要定义的宏的名字，这样就相当于在代码中定义了一个宏，其名字为DEBUG。
在CMake中我们也可以做类似的事情，对应的命令叫做add_definitions
    add_definitions(-D宏名称)
]]
add_definitions(-DHBLJ_LOG)


# (单行注释) “#”
# (多行注释) “#[[...]]”

#[[
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
]]

#[[
# SET 指令的语法是：
    # [] 中的参数为可选项, 如不需要可以不写
    SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE] ])

# 方式1: 各个源文件之间使用空格间隔
# set(SRC_LIST add.c  div.c   main.c  mult.c  sub.c)

# 方式2: 各个源文件之间使用分号 ; 间隔
set(SRC_LIST add.c;div.c;main.c;mult.c;sub.c)
add_executable(app  ${SRC_LIST})


0. 在编译的时候在编译命令中制定出要使用哪个标准
g++ *.cpp -std=c++11 -o app

1. 在 CMakeLists.txt 中通过 set 命令指定
#增加-std=c++11
set(CMAKE_CXX_STANDARD 11)
#增加-std=c++14
set(CMAKE_CXX_STANDARD 14)
#增加-std=c++17
set(CMAKE_CXX_STANDARD 17)

2. 在执行 cmake 命令的时候指定出这个宏的值
#增加-std=c++11
cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=11
#增加-std=c++14
cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=14
#增加-std=c++17
cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=17

***** PROJECT_SOURCE_DIR 宏对应的值就是我们在使用cmake命令时，后面紧跟的目录，一般是工程的根目录
]]
set(HOME ${PROJECT_SOURCE_DIR})
set(OUTPUTPATH ${HOME}/bin)
set (OBJ_TMP ${OUTPUTPATH}/obj)

#[[
在CMake中指定可执行程序输出的路径，也对应一个宏，叫做EXECUTABLE_OUTPUT_PATH，它的值还是通过set命令进行设置
    set(HOME /home/robin/Linux/Sort)
    set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
    第一行：定义一个变量用于存储一个绝对路径
    第二行：将拼接好的路径值设置给 EXECUTABLE_OUTPUT_PATH 宏
    如果这个路径中的子目录不存在，会自动生成，无需自己手动创建
    由于可执行程序是基于 cmake 命令生成的 makefile 文件然后再执行 make 命令得到的，所以如果此处指定可执行程序生成路径的时候使用的是相
        对路径 ./xxx/xxx，那么这个路径中的 ./ 对应的就是 makefile 文件所在的那个目录。

通过set命令给EXECUTABLE_OUTPUT_PATH宏设置了一个路径，这个路径就是可执行文件生成的路径
由于在Linux下生成的静态库默认不具有可执行权限，所以在指定静态库生成的路径的时候就不能使用 EXECUTABLE_OUTPUT_PATH 宏了，
而应该使用 LIBRARY_OUTPUT_PATH ，这个宏对应静态库文件和动态库文件都适用。
]]
set(EXECUTABLE_OUTPUT_PATH ${OUTPUTPATH})
set(LIBRARY_OUTPUT_PATH ${OUTPUTPATH}/lib)

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

#[[
1. 在 CMake 中使用aux_source_directory 命令可以查找某个路径下的所有源文件
aux_source_directory(< dir > < variable >)
    dir：要搜索的目录
    variable：将从dir目录下搜索到的源文件列表存储到该变量中

2. file(GLOB/GLOB_RECURSE 变量名 要搜索的文件路径和文件类型)
    GLOB: 将指定目录下搜索到的满足条件的所有文件名生成一个列表，并将其存储到变量中。
    GLOB_RECURSE：递归搜索指定目录，将搜索到的满足条件的文件名生成一个列表，并将其存储到变量中。
    如，搜索当前目录的src目录下所有的源文件，并存储到变量中：
    file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
    file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
            **** CMAKE_CURRENT_SOURCE_DIR 宏表示当前访问的 CMakeLists.txt 文件所在的路径

关于要搜索的文件路径和类型可加双引号，也可不加:
    file(GLOB MAIN_HEAD "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
]]
aux_source_directory(${HOME} CPP_FILES)

#[[
在cmake中，链接静态库的命令如下：
    link_libraries(<static lib> [<static lib>...])
    用于设置全局链接库，这些库会链接到之后定义的所有目标上。
        参数1：指定出要链接的静态库的名字
        可以是全名 libxxx.a
        也可以是掐头（lib）去尾（.a）之后的名字 xxx
        参数2-N：要链接的其它静态库的名字

如果该静态库不是系统提供的（自己制作或者使用第三方提供的静态库）可能出现静态库找不到的情况，此时可以将静态库的路径也指定出来
    通过命令指定出要链接的动态库的位置，指定静态库位置使用的也是这个命令
    link_directories(<lib path>)
]]
link_directories(${LIBRARY_OUTPUT_PATH})
link_libraries(lib04)

#[[
add_executable：定义工程会生成一个可执行程序, 这里的可执行程序名和project中的项目名没有任何关系，可以任意指定。
    # 样式1
    add_executable(app add.c div.c main.c mult.c sub.c)
    # 样式2
    add_executable(app add.c;div.c;main.c;mult.c;sub.c)
]]
add_executable(app01 ${CPP_FILES})

#[[
在cmake中链接动态库的命令如下:
    target_link_libraries(
        <target> 
        <PRIVATE|PUBLIC|INTERFACE> <item>... 
        [<PRIVATE|PUBLIC|INTERFACE> <item>...]...)
    用于指定一个目标（如可执行文件或库）在编译时需要链接哪些库。它支持指定库的名称、路径以及链接库的顺序
        target：指定要加载的库的文件的名字
            该文件可能是一个源文件
            该文件可能是一个动态库/静态库文件
            该文件可能是一个可执行文件
        PRIVATE|PUBLIC|INTERFACE：动态库的访问权限，默认为PUBLIC
            如果各个动态库之间没有依赖关系，无需做任何设置，三者没有没有区别，一般无需指定，使用默认的 PUBLIC 即可。
            动态库的链接具有传递性，如果动态库 A 链接了动态库B、C，动态库D链接了动态库A，此时动态库D相当于也链接了动态库B、C，并可以使用动态库B、C中定义的方法
                target_link_libraries(A B C)
                target_link_libraries(D A)
            PUBLIC：在public后面的库会被Link到前面的target中，并且里面的符号也会被导出，提供给第三方使用。
            PRIVATE：在private后面的库仅被link到前面的target中，并且终结掉，第三方不能感知你调了啥库
            INTERFACE：在interface后面引入的库不会被链接到前面的target中，只会导出符号。

链接系统动态库
    动态库的链接和静态库是完全不同的：
    静态库会在生成可执行程序的链接阶段被打包到可执行程序中，所以可执行程序启动，静态库就被加载到内存中了。
    动态库在生成可执行程序的链接阶段不会被打包到可执行程序中，当可执行程序被启动并且调用了动态库中的函数的时候，动态库才会被加载到内存
    因此，在cmake中指定要链接的动态库的时候，应该将命令写到生成了可执行文件之后
]]
target_link_libraries(app01 lib03)

#[[
如果在CMakeLists.txt文件所在目录执行了cmake命令之后就会生成一些目录和文件（包括 makefile 文件），如果再基于makefile文件执行make命令，
程序在编译过程中还会生成一些中间文件和一个可执行文件，这样会导致整个项目目录看起来很混乱，不太容易管理和维护，
此时我们就可以把生成的这些与项目源码无关的文件统一放到一个对应的目录里边，比如将这个目录命名为build
    mkdir build
    cd build
    cmake ..
]]

#[[
温馨提示：target_link_libraries 和  link_libraries 是 CMake 中用于链接库的两个命令，都可以用于链接动态库和静态库，但它们的使用场景和功能有所不同。下面是关于二者的总结：

target_link_libraries
    功能: target_link_libraries 用于指定一个目标（如可执行文件或库）在编译时需要链接哪些库。它支持指定库的名称、路径以及链接库的顺序
    优点:
        更精确地控制目标的链接库。
        可以指定库的不同链接条件（如调试版本、发布版本）。
        支持多个目标和多个库之间的复杂关系。
        更加灵活和易于维护，特别是在大型项目中
    示例:
        add_executable(my_executable main.cpp)
        target_link_libraries(my_executable PRIVATE my_dynamic_library)

link_libraries
    功能: link_libraries 用于设置全局链接库，这些库会链接到之后定义的所有目标上。它会影响所有的目标，适用于全局设置，但不如 target_link_libraries 精确
    缺点:
        缺乏针对具体目标的控制，不适合复杂的项目结构。
        容易导致意外的依赖关系，因为它对所有目标都生效。
        一旦设置，全局影响可能导致难以追踪的链接问题

总结
    target_link_libraries 是更推荐的方式，因为它允许更精确的控制和管理链接库的依赖，特别是在大型项目中，它能够避免全局设置可能带来的问题。
    link_libraries 虽然简单，但在复杂的项目中可能会导致意外的问题，通常适用于简单的项目或临时设置。
    建议在 CMake 项目中优先使用 target_link_libraries
]]

#[[
变量操作
追加
    有时候项目中的源文件并不一定都在同一个目录中，但是这些源文件最终却需要一起进行编译来生成最终的可执行文件或者库文件。
    如果我们通过file命令对各个目录下的源文件进行搜索，最后还需要做一个字符串拼接的操作，关于字符串拼接可以使用set命令也可以使用list命令
    如果使用list进行字符串拼接，对应的命令格式如下
        list(APPEND <list> [<element> ...])
            list命令的功能比set要强大，字符串拼接只是它的其中一个功能，所以需要在它第一个参数的位置指
            定出我们要做的操作，APPEND表示进行数据追加，后边的参数和set就一样了。
        # 追加(拼接)
            list(APPEND SRC_1 ${SRC_1} ${SRC_2} ${TEMP})
字符串移除
    当前这么目录有五个源文件，其中main.cpp是一个测试文件。如果我们想要把计算器相关的源文件生成一个动态库给别人使用，那么只需
    要add.cpp、div.cp、mult.cpp、sub.cpp这四个源文件就可以了。此时，就需
    要将main.cpp从搜索到的数据中剔除出去，想要实现这个功能，也可以使用list
        list(REMOVE_ITEM <list> <value> [<value> ...])
    # 移除 main.cpp
        list(REMOVE_ITEM SRC_1 ${PROJECT_SOURCE_DIR}/main.cpp)

    **** 一定要注意通过 file 命令搜索源文件的时候得到的是文件的绝对路径（在list中每个文件对应的路径都是一个item，并且都是绝对路径），
        那么在移除的时候也要将该文件的绝对路径指定出来才可以，否是移除操作不会成功

获取 list 的长度。
    list(LENGTH <list> <output variable>)
读取列表中指定索引的的元素，可以指定多个索引
将列表中的元素用连接符（字符串）连接起来组成一个字符串
查找列表是否存在指定的元素，若果未找到，返回-1
将元素追加到列表中
在list中指定的位置插入若干元素
将元素插入到列表的0索引位置
将列表中最后元素移除
将列表中第一个元素移除
将指定的元素从列表中移除
将指定索引的元素从列表中移除
移除列表中的重复元素
列表翻转
列表排序
    list (SORT <list> [COMPARE <compare>] [CASE <case>] [ORDER <order>])
        COMPARE：指定排序方法。有如下几种值可选：
        STRING:按照字母顺序进行排序，为默认的排序方法
        FILE_BASENAME：如果是一系列路径名，会使用basename进行排序
        NATURAL：使用自然数顺序排序
        CASE：指明是否大小写敏感。有如下几种值可选：
        SENSITIVE: 按照大小写敏感的方式进行排序，为默认值
        INSENSITIVE：按照大小写不敏感方式进行排序
        ORDER：指明排序的顺序。有如下几种值可选：
        ASCENDING:按照升序排列，为默认值
        DESCENDING：按照降序排列
]]

#[[
CMake中常用的宏：
    PROJECT_SOURCE_DIR                  使用cmake命令后紧跟的目录，一般是工程的根目录
    PROJECT_BINARY_DIR                  执行cmake命令的目录
    CMAKE_CURRENT_SOURCE_DIR            当前处理的CMakeLists.txt所在的路径
    CMAKE_CURRENT_BINARY_DIR            target 编译目录
    EXECUTABLE_OUTPUT_PATH              重新定义目标二进制可执行文件的存放位置
    LIBRARY_OUTPUT_PATH                 重新定义目标链接库文件的存放位置
    PROJECT_NAME                        返回通过PROJECT指令定义的项目名称
    CMAKE_BINARY_DIR                    项目实际构建路径，假设在build目录进行的构建，那么得到的就是这个目录的路径
]]

#[[
动态链接器
默认的搜索顺序，按照优先级从高到低的顺序分别是

    1. 可执行文件内部的 DT_RPATH 段

    2. 系统的环境变量 LD_LIBRARY_PATH

    3. 系统动态库的缓存文件 /etc/ld.so.conf.d 目录下的 *.conf 文件中 包含的目录

    4. 存储动态库/静态库的系统目录 /lib/, /usr/lib等

    按照以上四个顺序, 依次搜索, 找到之后结束遍历, 最终还是没找到, 动态连接器就会提示动态库找不到的错误信息
]]