set(LIB_NAME Security)
set(LIB_SRC_ROOT_DIR ${Library_DIR}/Security)
message(${LIB_NAME}:LIB_SRC_ROOT_DIR=${LIB_SRC_ROOT_DIR})

include_directories(
    ${LIB_SRC_ROOT_DIR} 
)
aux_source_directory(${LIB_SRC_ROOT_DIR}/base64 base64)
aux_source_directory(${LIB_SRC_ROOT_DIR}/crc32 crc32)
aux_source_directory(${LIB_SRC_ROOT_DIR}/des des)
aux_source_directory(${LIB_SRC_ROOT_DIR}/md5 md5)
aux_source_directory(${LIB_SRC_ROOT_DIR}/uuid uuid)

set(SRC_FILES ${base64} ${crc32} ${des} ${md5} 
    ${uuid} 
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
# ##################安装Security头文件########################
# set(CMAKE_INSTALL_PREFIX )
# file(INSTALL DESTINATION "${ROOT_DIR}/modules/CBB_Source/CBB_Release/include" TYPE DIRECTORY FILES 
#         "/home/r22116/A810/a810v2010/UpgradeService/modules/CBB_Source/Library/Security" 
#         PATTERN "tools" EXCLUDE
#         PATTERN ".*" EXCLUDE
#         PATTERN "*.mk" EXCLUDE
#         PATTERN "*.md" EXCLUDE
#         PATTERN "*.sh" EXCLUDE
#         PATTERN "*.txt" EXCLUDE
#         PATTERN "Makefile" EXCLUDE
# )