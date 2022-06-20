set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)
message(BOARD_TYPE=${BOARD_TYPE})
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
message(ROOT_DIR=${ROOT_DIR})
# set(CMAKE_BUILD_TYPE Release)
if (${BOARD_TYPE} STREQUAL 1881)
	set( SYSROOT         /home/r22116/code/bak/LC1881/arm64-v8a/sysroot)
	set( SYSTEM_PLAT      LC1881)
	set( CROSS_COMPILE    aarch64-linux-android-)
	set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -DCHIPSET_LC1881")
elseif (${BOARD_TYPE} STREQUAL 3403)
	set( SYSTEM_PLAT      HI3403)
	set( CROSS_COMPILE    aarch64-himix210-linux-)
	set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -DHISI_SDK_VERSION=0x3403")
elseif (${BOARD_TYPE} STREQUAL 810)
	set( SYSTEM_PLAT      A810)
	set( CROSS_COMPILE    aarch64-mix210-linux-)
	set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -DHISI_SDK_VERSION=0xA8102010")
elseif (${BOARD_TYPE} STREQUAL A810)
	set( SYSTEM_PLAT      A810A)
	set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -DHISI_SDK_VERSION=0xA8102022")
	set( CROSS_COMPILE    aarch64-mix210-linux-)
elseif (${BOARD_TYPE} STREQUAL 3559V2)
	set( SYSTEM_PLAT      HI3559V2)
	set( CROSS_COMPILE    arm-himix410-linux-)
	set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -DHISI_SDK_VERSION=0x3559200")
elseif (${BOARD_TYPE} STREQUAL 3559A)
	set( SYSTEM_PLAT      HI3559A)
	set( CROSS_COMPILE    aarch64-himix100-linux-)
	set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -DHISI_SDK_VERSION=0x3559020")
endif()

set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -Wall -O2 -std=c++11 -fno-strict-aliasing")
set(CMAKE_C_FLAGS   "${CAMKE_CXX_FLAGS} -Wall -O2 -std=c++11 -fno-strict-aliasing")

# ifeq ($(SYSTEM_PLAT), HI3403)
# 	CFLAGS := -Wall -O2 -c -fmessage-length=0 -DHISI_SDK_VERSION=0x3403 -Wno-placement-new
# else ifeq ($(SYSTEM_PLAT), A810)
# 	CFLAGS := -Wall -O2 -c -fmessage-length=0 -DHISI_SDK_VERSION=0xA8102010 -Wno-placement-new
# else ifeq ($(SYSTEM_PLAT), A810A)
# 	CFLAGS := -Wall -O2 -c -fmessage-length=0 -DHISI_SDK_VERSION=0xA8102022 -Wno-placement-new
# else ifeq ($(SYSTEM_PLAT), HI3559V2)
# 	CFLAGS := -Wall -O2 -c -fmessage-length=0 -DHISI_SDK_VERSION=0x3559200 -Wno-placement-new
# else ifeq ($(SYSTEM_PLAT), HI3559A)
# 	CFLAGS := -Wall -O2 -c -fmessage-length=0 -DHISI_SDK_VERSION=0x3559020 -Wno-placement-new -Wno-strict-aliasing
# else ifeq ($(SYSTEM_PLAT), LC1881)
# 	CFLAGS := -Wall -O2 -c -fmessage-length=0 -DCHIPSET_LC1881 -Wno-address-of-packed-member
# endif
# # 设置目标系统
# set(CMAKE_SYSTEM_NAME Linux)
# set(CMAKE_SYSTEM_PROCESSOR aarch64)
# # 设置工具链目录
# set(TOOL_CHAIN_DIR /home/r22116/code/bak/LC1881/tools/arm64-v8a)
# set(TOOL_CHAIN_INCLUDE 
# 	${TOOL_CHAIN_DIR}/sysroot/usr/include
# 	${TOOL_CHAIN_DIR}/include
# 	)
# set(TOOL_CHAIN_LIB 
# 	${TOOL_CHAIN_DIR}/sysroot/usr/lib
# 	${TOOL_CHAIN_DIR}/lib
# 	)
# 设置编译器位置
message("CROSS_COMPILE: " ${CROSS_COMPILE})
set(CMAKE_C_COMPILER   ${CROSS_COMPILE}gcc)
set(CMAKE_CXX_COMPILER ${CROSS_COMPILE}g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILEON ON)

# # 设置Cmake查找主路径
# set(CMAKE_FIND_ROOT_PATH ${TOOL_CHAIN_DIR}/sysroot)

# set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# # 只在指定目录下查找库文件
# set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# # 只在指定目录下查找头文件
# set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# # 只在指定目录下查找依赖包
# set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# include_directories(
# 	${TOOL_CHAIN_DIR}/include
# 	${TOOL_CHAIN_DIR}/sysroot/usr/include
# 	)

# set(CMAKE_INCLUDE_PATH 
# 	${TOOL_CHAIN_INCLUDE}
# 	)

# set(CMAKE_LIBRARY_PATH 
# 	${TOOL_CHAIN_LIB}
# 	)

# set(ARCH  "aarch64")
# if(${ARCH} STREQUAL "x86_64")
# 	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -g")
# 	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread  -g")
# endif()
