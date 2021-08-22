cmake_minimum_required(VERSION 3.15)
project(tem_algrithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCONFIG_LLT -fprofile-arcs -ftest-coverage")

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../AccountMangerTest/)
aux_source_directory(./source source)

set(SRC_FILES
        ${source}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"/run)

add_executable(template ${SRC_FILES})
# target_link_libraries(template libmockcpp.a libgmock.a libgtest.a) 