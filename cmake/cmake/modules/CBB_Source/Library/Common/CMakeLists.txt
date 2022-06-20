set(LIB_NAME Common)
set(LIB_SRC_ROOT_DIR ${Library_DIR}/Common)
message(${LIB_NAME}:LIB_SRC_ROOT_DIR=${LIB_SRC_ROOT_DIR})

include_directories(
    ${LIB_SRC_ROOT_DIR}
    ${LIB_SRC_ROOT_DIR}/../../CBB_Release/include
    ${LIB_SRC_ROOT_DIR}/../../CBB_Release/include/Common
    ${LIB_SRC_ROOT_DIR}/../../CBB_Release/include/Security             
)
aux_source_directory(${LIB_SRC_ROOT_DIR}/device device)
aux_source_directory(${LIB_SRC_ROOT_DIR}/general general)
aux_source_directory(${LIB_SRC_ROOT_DIR}/json json)
aux_source_directory(${LIB_SRC_ROOT_DIR}/message message)
aux_source_directory(${LIB_SRC_ROOT_DIR}/sharememory sharememory)
aux_source_directory(${LIB_SRC_ROOT_DIR}/systemutils systemutils)

set(SRC_FILES ${device} ${general} ${json} ${message} 
    ${sharememory} ${systemutils}
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
#         REGEX "/*.c$" EXCLUDE)
# ##################安装Common头文件########################
# set(CMAKE_INSTALL_PREFIX )
# file(INSTALL DESTINATION "${ROOT_DIR}/modules/CBB_Source/CBB_Release/include" TYPE DIRECTORY FILES 
#         "/home/r22116/A810/a810v2010/UpgradeService/modules/CBB_Source/Library/Common" 
#         PATTERN "tools" EXCLUDE
#         PATTERN ".*" EXCLUDE
#         PATTERN "*.mk" EXCLUDE
#         PATTERN "*.md" EXCLUDE
#         PATTERN "*.sh" EXCLUDE
#         PATTERN "*.txt" EXCLUDE
#         PATTERN "Makefile" EXCLUDE
# )