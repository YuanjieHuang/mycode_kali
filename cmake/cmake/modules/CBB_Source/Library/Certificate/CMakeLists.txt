set(LIB_NAME Certificate)
set(LIB_SRC_ROOT_DIR ${Library_DIR}/Certificate)
message(${LIB_NAME}:LIB_SRC_ROOT_DIR=${LIB_SRC_ROOT_DIR})

include_directories(
    ${LIB_SRC_ROOT_DIR}
    ${LIB_SRC_ROOT_DIR}/mincrypt
    ${LIB_SRC_ROOT_DIR}/minzip
    ${LIB_SRC_ROOT_DIR}/minzip/safe-iop/include
)


file(GLOB SRC_FILES_cur LIST_DIRECT false ABSTRACT ${LIB_SRC_ROOT_DIR} *.cpp)
file(GLOB SRC_FILES_crypt LIST_DIRECT false ABSTRACT ${LIB_SRC_ROOT_DIR} mincrypt/*.c)
file(GLOB SRC_FILES_zip LIST_DIRECT false ABSTRACT ${LIB_SRC_ROOT_DIR} minzip/*.c)

set(SRC_FILES ${SRC_FILES_cur} ${SRC_FILES_crypt} ${SRC_FILES_zip} 
    ${LIB_SRC_ROOT_DIR}/minzip/safe-iop/src/safe_iop.c
)

ADD_LIBRARY(${LIB_NAME} SHARED ${SRC_FILES})
ADD_LIBRARY(${LIB_NAME}_static STATIC ${SRC_FILES})
SET_TARGET_PROPERTIES(${LIB_NAME}_static PROPERTIES OUTPUT_NAME "${LIB_NAME}")

# install(TARGETS ${LIB_NAME} ${LIB_NAME}_static
#     LIBRARY DESTINATION lib
#     ARCHIVE DESTINATION lib
# )
# install(DIRECTORY ${LIB_SRC_ROOT_DIR} DESTINATION include/${LIB_NAME}
#         PATTERN ".git" EXCLUDE
#         PATTERN "out" EXCLUDE
#         PATTERN "cmake" EXCLUDE
#         PATTERN "*.cpp" EXCLUDE
#         PATTERN "*.mk" EXCLUDE
#         PATTERN "*.sh" EXCLUDE
#         PATTERN "*.txt" EXCLUDE
#         PATTERN "*.o" EXCLUDE
#         PATTERN "Makefile" EXCLUDE
#         REGEX "/*.c$" EXCLUDE
# )
# ##################安装boost头文件########################
# set(CMAKE_INSTALL_PREFIX )
# file(INSTALL DESTINATION "${ROOT_DIR}/modules/CBB_Source/include" TYPE DIRECTORY FILES 
#         "/home/r22116/A810/a810v2010/UpgradeService/modules/CBB_Source/Library/Certificate" 
#         PATTERN "tools" EXCLUDE
#         PATTERN ".*" EXCLUDE
#         PATTERN "*.mk" EXCLUDE
#         PATTERN "*.md" EXCLUDE
#         PATTERN "*.sh" EXCLUDE
#         PATTERN "*.txt" EXCLUDE
#         PATTERN "Makefile" EXCLUDE
# )