set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCONFIG_LLT -fprofile-arcs -ftest-coverage -lm -w -lcrypt  -lxml2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCONFIG_LLT -fprofile-arcs -ftest-coverage")
# set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/biuld/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

include_directories("/usr/include/libxml2" "/usr/include")
link_directories()

# file(GLOB_RECURSE allCSrcs "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
# message("files " ${allCSrcs})
file( GLOB_RECURSE allCSrcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
message("files " ${allCSrcs})
foreach(src IN LISTS allCSrcs)
    string(REPLACE ".c" "" obj ${src})
    get_filename_component(tarName ${obj} NAME)
    get_filename_component(tarPath ${obj} PATH)
    message("tarPath " ${tarPath})
    # set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/${tarPath})
    # add_executable(${tarName} ${src})
endforeach()

# get_filename_component(tarName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# aux_source_directory(. SRC)
# file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp)
# add_executable(${tarName} ${SRC} ${CURRENT_HEADERS})
# add_test(NAME ${tarName} COMMAND ${tarName})
# set_target_properties(${tarName} PROPERTIES FOLDER "DesignPattern")

#[[
# If necessary, use the RELATIVE flag, otherwise each source file may be listed 
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
file( GLOB APP_SOURCES RELATIVE *.c)
file( GLOB APP_SOURCES *.c )
]]

#[[
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} my)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/function functions)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/linux_learn_c linux_learn_cs)
set(SRCS ${my} ${functions} )
foreach(src ${SRCS})
    string(REPLACE ".c" "" obj ${src})
    get_filename_component(tarName ${obj} NAME)
    # message("src" ${obj})
    add_executable(${tarName} ${src})
    target_link_libraries( ${testname} YourLib )
endforeach(src ${SRCS})
]]