
#CMakeLists.txt
cmake_minimum_required(VERSION 3.18.2)
project(include_directories_test)

include_directories(sub) 
include_directories(sub2) #默认将sub2添加到列表最后
include_directories(BEFORE sub3) #可以临时改变行为，添加到列表最前面

get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> include_dirs=${dirs}") #打印一下目录情况

set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON) #改变默认行为，默认添加到列表前面
include_directories(sub4)
include_directories(AFTER sub5) #可以临时改变行为，添加到列表的最后
get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> SET DEFAULT TO BEFORE, include_dirs=${dirs}")

#输出
>>> include_dirs=/XXX/XXX/sub3;/XXX/XXX/sub;/XXX/XXX/sub2
>>> SET DEFAULT TO BEFORE, include_dirs=/XXX/XXX/sub4;/XXX/XXX/sub3;/XXX/XXX/sub;/XXX/XXX/sub2;/XXX/XXX/sub5