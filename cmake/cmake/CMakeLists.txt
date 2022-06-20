cmake_minimum_required(VERSION 3.5)
project(UpgradeService)
include(common.cmake)

add_subdirectory(modules)
# add_subdirectory( unit_test )
#[[
include_directories(
    ${ROOT_DIR}/src
    ${ROOT_DIR}/include
    ${ROOT_DIR}/include/CBB_Release/include
    ${ROOT_DIR}/include/CBB_Release/include/Common
    ${ROOT_DIR}/include/CBB_Release/include/GeneralHeader
    ${ROOT_DIR}/include/CBB_Release/include/Security
    ${ROOT_DIR}/include/CBB_Release/include/Certificate
)
aux_source_directory(${ROOT_DIR}/src src)

link_directories(
    ${ROOT_DIR}/lib
    ${ROOT_DIR}/lib/CBB_Release
)
set( SRC_FILES ${src} )

if (${SYSTEM_PLAT} STREQUAL  "LC1881")
	set(LIBS libCommon.so libSecurity.so libCertificate.so dl)
else()
    set(LIBS libCommon.so libSecurity.so libCertificate.so libenv.a pthread dl)
endif()

set(CMAKE_INSTALL_PREFIX ${ROOT_DIR})
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBS})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
]]
