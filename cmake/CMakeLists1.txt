cmake_minimum_required(VERSION 3.5)
project(Certificate)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILEON ON)
set(LIB_NAME cert)
include(cmake/ToolChans.cmake)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_compile_options(-Wall -std=c++11 -o2)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/mincrypt
    ${CMAKE_CURRENT_SOURCE_DIR}/minzip
    ${CMAKE_CURRENT_SOURCE_DIR}/minzip/safe-iop/include
)

file(GLOB SRC_FILES_cur LIST_DIRECT false ABSTRACT ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
file(GLOB SRC_FILES_crypt LIST_DIRECT false ABSTRACT ${CMAKE_CURRENT_SOURCE_DIR} mincrypt/*.c)
file(GLOB SRC_FILES_zip LIST_DIRECT false ABSTRACT ${CMAKE_CURRENT_SOURCE_DIR} minzip/*.c)

set(SRC_FILES ${SRC_FILES_cur} ${SRC_FILES_crypt} ${SRC_FILES_zip} ${CMAKE_CURRENT_SOURCE_DIR}/minzip/safe-iop/src/safe_iop.c)

ADD_LIBRARY(${LIB_NAME} SHARED ${SRC_FILES})
ADD_LIBRARY(${LIB_NAME}_static STATIC ${SRC_FILES})
SET_TARGET_PROPERTIES(${LIB_NAME}_static PROPERTIES OUTPUT_NAME "${LIB_NAME}")
SET_TARGET_PROPERTIES(${LIB_NAME} PROPERTIES VERSION 1.2 SOVERSION 1)

target_include_directories(${LIB_NAME} PUBLIC  ${CMAKE_SOURCE_DIR})
file(GLOB_RECURSE headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

foreach(header IN LISTS headers)
    set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/${header})
    message("header files:" ${CMAKE_SOURCE_DIR}/${header})
endforeach()


set(CBB_Source_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(CBB_Release ${CBB_Source_DIR}/CBB_Release)
set(INSTALL_HEAD_FILES ${CBB_Source_DIR}/CBB_Release)
message(CBB_Source_DIR=${CBB_Source_DIR})
set(CMAKE_INSTALL_PREFIX ${CBB_Release})
# message(CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX})
install(TARGETS ${LIB_NAME} 
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
#   RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER  DESTINATION include
    PRIVATE_HEADER DESTINATION include
)