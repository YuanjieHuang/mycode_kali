cmake_minimum_required(VERSION 3.5)
set(CMAKE_VERBOSE_MAKEFILEON ON)
include(common.cmake)

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
# message(${SRC_FILES})
{Certificate,Common,Security}
ADD_LIBRARY(cert SHARED ${SRC_FILES})