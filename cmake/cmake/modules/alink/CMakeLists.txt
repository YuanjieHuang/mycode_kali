##################安装alink头文件########################
set(CMAKE_INSTALL_PREFIX )
file(INSTALL DESTINATION "${ROOT_DIR}/include" TYPE DIRECTORY FILES 
        "/home/r22116/A810/a810v2010/UpgradeService/modules/alink" 
        PATTERN "tools" EXCLUDE
        PATTERN ".*" EXCLUDE
        PATTERN "*.mk" EXCLUDE
        PATTERN "*.md" EXCLUDE
        PATTERN "*.sh" EXCLUDE
        PATTERN "*.txt" EXCLUDE
        PATTERN "Makefile" EXCLUDE
)
