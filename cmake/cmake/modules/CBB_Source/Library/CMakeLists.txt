##################安装Certificate头文件########################
set(CMAKE_INSTALL_PREFIX )
file(INSTALL DESTINATION "${ROOT_DIR}/modules/CBB_Source/CBB_Release/include" TYPE DIRECTORY FILES 
        "/home/r22116/A810/a810v2010/UpgradeService/modules/CBB_Source/Library/Certificate" 
        PATTERN "tools" EXCLUDE
        PATTERN ".*" EXCLUDE
        PATTERN "*.mk" EXCLUDE
        PATTERN "*.md" EXCLUDE
        PATTERN "*.sh" EXCLUDE
        PATTERN "*.txt" EXCLUDE
        PATTERN "Makefile" EXCLUDE
        PATTERN ".git" EXCLUDE
        PATTERN "out" EXCLUDE
        PATTERN "cmake" EXCLUDE
        PATTERN "*.cpp" EXCLUDE
        PATTERN "*.mk" EXCLUDE
        PATTERN "*.sh" EXCLUDE
        PATTERN "*.txt" EXCLUDE
        PATTERN "*.o" EXCLUDE
        PATTERN "Makefile" EXCLUDE
        REGEX "/*.c$" EXCLUDE
)
##################安装Common头文件########################
set(CMAKE_INSTALL_PREFIX )
file(INSTALL DESTINATION "${ROOT_DIR}/modules/CBB_Source/CBB_Release/include" TYPE DIRECTORY FILES 
        "/home/r22116/A810/a810v2010/UpgradeService/modules/CBB_Source/Library/Common" 
        PATTERN "tools" EXCLUDE
        PATTERN ".*" EXCLUDE
        PATTERN "*.mk" EXCLUDE
        PATTERN "*.md" EXCLUDE
        PATTERN "*.sh" EXCLUDE
        PATTERN "*.txt" EXCLUDE
        PATTERN "Makefile" EXCLUDE
        PATTERN ".git" EXCLUDE
        PATTERN "out" EXCLUDE
        PATTERN "cmake" EXCLUDE
        PATTERN "*.cpp" EXCLUDE
        PATTERN "*.mk" EXCLUDE
        PATTERN "*.sh" EXCLUDE
        PATTERN "*.txt" EXCLUDE
        PATTERN "*.o" EXCLUDE
        PATTERN "Makefile" EXCLUDE
        REGEX "/*.c$" EXCLUDE
)
##################安装Security头文件########################
set(CMAKE_INSTALL_PREFIX )
file(INSTALL DESTINATION "${ROOT_DIR}/modules/CBB_Source/CBB_Release/include" TYPE DIRECTORY FILES 
        "/home/r22116/A810/a810v2010/UpgradeService/modules/CBB_Source/Library/Security" 
        PATTERN "tools" EXCLUDE
        PATTERN ".*" EXCLUDE
        PATTERN "*.mk" EXCLUDE
        PATTERN "*.md" EXCLUDE
        PATTERN "*.sh" EXCLUDE
        PATTERN "*.txt" EXCLUDE
        PATTERN "Makefile" EXCLUDE
        PATTERN ".git" EXCLUDE
        PATTERN "out" EXCLUDE
        PATTERN "cmake" EXCLUDE
        PATTERN "*.cpp" EXCLUDE
        PATTERN "*.mk" EXCLUDE
        PATTERN "*.sh" EXCLUDE
        PATTERN "*.txt" EXCLUDE
        PATTERN "*.o" EXCLUDE
        PATTERN "Makefile" EXCLUDE
        REGEX "/*.c$" EXCLUDE
)

set(Library_DIR ${ROOT_DIR}/modules/CBB_Source/Library)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -Wall -fPIC -O2 -std=c++11 -fno-strict-aliasing ")
set(CMAKE_C_FLAGS   "${CAMKE_CXX_FLAGS} -Wall -fPIC -O2 -std=c++11 -fno-strict-aliasing ")
add_subdirectory( Certificate )
add_subdirectory( Common )
add_subdirectory( Security )
##################安装boost头文件########################
set(CMAKE_INSTALL_PREFIX )
file(INSTALL DESTINATION "${ROOT_DIR}/modules/CBB_Source/CBB_Release" TYPE DIRECTORY FILES 
        "/home/r22116/A810/a810v2010/UpgradeService/modules/CBB_Source/Library/include" 
        PATTERN "tools" EXCLUDE
        PATTERN ".*" EXCLUDE
        PATTERN "*.mk" EXCLUDE
        PATTERN "*.md" EXCLUDE
        PATTERN "*.sh" EXCLUDE
        PATTERN "*.txt" EXCLUDE
        PATTERN "Makefile" EXCLUDE
)
set(CBB_Release ${ROOT_DIR}/modules/CBB_Source/CBB_Release)
# set(CMAKE_INSTALL_PREFIX ${ROOT_DIR}/modules/CBB_Source/CBB_Release)
# message(${LIB_NAME}:CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX})
# set(CMAKE_INSTALL_PREFIX ${ROOT_DIR}/modules/CBB_Source/CBB_Release)
# message(${LIB_NAME}:CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX})
set(LIBRARY_OUTPUT_DIRECTORY ${CBB_Release}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CBB_Release}/lib)