cmake_minimum_required(VERSION 3.0)
project(Installation VERSION 1.0)
set(LIB_NAME mymath)
# # # 如果想生成静态库，使用下面的语句
add_library(${LIB_NAME}_static STATIC mymath.cc)
target_include_directories(${LIB_NAME}_static PUBLIC ${CMAKE_SOURCE_DIR})
SET_TARGET_PROPERTIES(${LIB_NAME}_static PROPERTIES OUTPUT_NAME "${LIB_NAME}")

# 如果想生成动态库，使用下面的语句
add_library(${LIB_NAME} SHARED mymath.cc)
# target_include_directories(${LIB_NAME} PRIVATE  ${CMAKE_SOURCE_DIR})
set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/mymath.h)
SET_TARGET_PROPERTIES(${LIB_NAME} PROPERTIES VERSION 1.2 SOVERSION 1)

# # 生成可执行文件
add_executable(${LIB_NAME}app mymathApp.cc)
target_link_libraries(${LIB_NAME}app ${LIB_NAME})
target_include_directories(${LIB_NAME}app PRIVATE ${CMAKE_SOURCE_DIR})
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
# # 将库文件，可执行文件，头文件安装到指定目录
install(TARGETS ${LIB_NAME} ${LIB_NAME}app
        EXPORT MyMathTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include
        PRIVATE_HEADER DESTINATION include
       )