set(EXE_SERVER server)
set(LIB_SRC_ROOT_DIR ${ROOT_DIR}/modules/CBB_Source/CenterServer)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -Wall  -O2 -std=c++11 -fno-strict-aliasing ")
set(CMAKE_C_FLAGS   "${CAMKE_CXX_FLAGS} -Wall  -O2 -std=c++11 -fno-strict-aliasing ")
# if(${})
message(${EXE_SERVER}LIB_SRC_ROOT_DIR=${LIB_SRC_ROOT_DIR})
include_directories( ${LIB_SRC_ROOT_DIR}/src 
    ${LIB_SRC_ROOT_DIR}/../CBB_Release/include
    ${LIB_SRC_ROOT_DIR}/../CBB_Release/include/Common
    ${LIB_SRC_ROOT_DIR}/../CBB_Release/include/Security

)
aux_source_directory(${LIB_SRC_ROOT_DIR}/src src)

set(SRC_FILES ${src} )

if (${SYSTEM_PLAT} STREQUAL  "LC1881")
	set(LIBS libCommon.so libSecurity.so dl)
else()
    set(LIBS libCommon.so libSecurity.so pthread dl)
endif()

set(UpgradeService_DIR ${ROOT_DIR}/..)
set(ROOT ${UpgradeService_DIR})
set(LIB_DIR ${ROOT}/lib)
set(BIN_DIR ${ROOT}/bin)

set(CMAKE_INSTALL_PREFIX ${LIB_SRC_ROOT_DIR}/../CBB_Release/bin)
link_directories( ${LIB_SRC_ROOT_DIR}/../CBB_Release/lib )
add_executable(${EXE_SERVER} ${SRC_FILES})
target_link_libraries(${EXE_SERVER} ${LIBS})
install(TARGETS ${EXE_SERVER} RUNTIME DESTINATION bin)
if (${SYSTEM_PLAT} STREQUAL  "LC1881")
    install(FILES ${ROOT_DIR}/init.ini.lc1881 DESTINATION bin RENAME init.ini)
else()
    install(FILES ${ROOT_DIR}/init.ini DESTINATION bin)
endif()
