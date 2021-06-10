去哪找头文件（.h），-I（GCC）

    INCLUDE_DIRECTORIES()

去哪找库文件（.so/.dll/.lib/.dylib/...），-L（GCC）

    LINK_DIRECTORIES()

需要链接的库文件的名字：-l（GCC）

    LINK_LIBRARIES(库名称即可)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(HelloWorld)
ADD_SUBDIRECTORY(src/hello)
INSTALL(PROGRAMS build/bin/hello DESTINATION /usr/local/bin/)