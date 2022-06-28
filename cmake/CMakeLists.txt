# cmake_minimum_required(VERSION 3.15)
# project(GtestLearnLLT)
message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
message(PROJECT_BINARY_DIR:${PROJECT_BINARY_DIR})
message(CMAKE_SOURCE_DIR:${CMAKE_SOURCE_DIR})
message(PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR})
message(CMAKE_CURRENT_BINARY_DIR:${CMAKE_CURRENT_BINARY_DIR})
message(CMAKE_CURRENT_LIST_DIR:${CMAKE_CURRENT_LIST_DIR})
message(CMAKE_CURRENT_LIST_LINE:${CMAKE_CURRENT_LIST_LINE})
message(CMAKE_MODULE_PATH:${CMAKE_MODULE_PATH})
message(LIBRARY_OUTPUT_DIR:${LIBRARY_OUTPUT_DIR})
message(BINARY_OUTPUT_DIR:${BINARY_OUTPUT_DIR})
message(CMAKE_INCLUDE_CURRENT_DIR:${CMAKE_INCLUDE_CURRENT_DIR})
message(CMAKE_INCLUDE_PATH:${CMAKE_INCLUDE_PATH})
message(CMAKE_LIBRARY_PATH:${CMAKE_LIBRARY_PATH})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# message(CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR})
# find_library(RUN_SERIAL TRUE )
#[[
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCONFIG_LLT -fprofile-arcs -ftest-coverage")
set(THIRD_PARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/third_party)

link_directories(${THIRD_PARTY_PATH}/mockcpp/lib
                ${THIRD_PARTY_PATH}/googlemock/lib
                ${THIRD_PARTY_PATH}/googletest/lib)

include_directories(${THIRD_PARTY_PATH}/googletest/include/
        ${THIRD_PARTY_PATH}/googlemock/include/
        ${THIRD_PARTY_PATH}/mockcpp/include/
        ${THIRD_PARTY_PATH}/mockcpp/3rdparty/
        ${THIRD_PARTY_PATH}/googlemock/

        ${CMAKE_CURRENT_SOURCE_DIR}/items/GtestLearn/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/items/AccountMangerTest/include
        ${CMAKE_CURRENT_SOURCE_DIR}/items/simpleTest/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../c/algorithm_c/algorithm/
)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../AccountMangerTest/)

aux_source_directory(./items/AccountMangerTest/source AccountMangerTest)
aux_source_directory(./items/simpleTest/source simpleTest)
aux_source_directory(./items/GtestLearn/source GtestLearn)
aux_source_directory(./source source)

set(SRC_FILES
        ${THIRD_PARTY_PATH}/googlemock/src/gmock-all.cc
        # ${CMAKE_CURRENT_SOURCE_DIR}/stubs/my_stubs.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../c/algorithm_c/algorithm/sort.c
        main.cpp
        ${AccountMangerTest}
        # ${simpleTest}
        ${GtestLearn}
        ${source}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(gtest ${SRC_FILES})
target_link_libraries(gtest libmockcpp.a libgmock.a libgtest.a) 
]]