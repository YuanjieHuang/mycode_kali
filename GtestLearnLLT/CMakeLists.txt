cmake_minimum_required(VERSION 3.15)
project(GtestLearnLLT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCONFIG_LLT -fprofile-arcs -ftest-coverage")
set(THIRD_PARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/third_party)

link_directories(${THIRD_PARTY_PATH}/mockcpp/lib
                ${THIRD_PARTY_PATH}/googlemock/lib
                ${THIRD_PARTY_PATH}/googletest/lib)

#${THIRD_PARTY_PATH}/googletest/
include_directories(${THIRD_PARTY_PATH}/googletest/include/
        ${THIRD_PARTY_PATH}/googlemock/include/
        ${THIRD_PARTY_PATH}/mockcpp/include/
        ${THIRD_PARTY_PATH}/mockcpp/3rdparty/
        ${THIRD_PARTY_PATH}/googlemock/
        ${CMAKE_CURRENT_SOURCE_DIR}/../GtestLearn/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/stubs/)

#${THIRD_PARTY_PATH}/googletest/src/gtest-all.cc
set(SRC_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/../GtestLearn/func.c
        # ${CMAKE_CURRENT_SOURCE_DIR}/../GtestLearn/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stubs/my_stubs.c
        ${THIRD_PARTY_PATH}/googlemock/src/gmock-all.cc
        gtest_ut.cpp
        main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(GtestLearnLLT ${SRC_FILES})
target_link_libraries(GtestLearnLLT libmockcpp.a libgmock.a libgtest.a)
