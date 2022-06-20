#
# CMakeLists.txt - cmake build file for API Design examples
#
# Martin Reddy, 1 Jan 2010 - http://APIBook.com/
#

# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.4)
project(callback_instance)
set(LIB_NAME ${PROJECT_NAME})
set(BINARY_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# Build the executable
add_executable(callback_instance main.cpp modulea.cpp moduleb.cpp)
