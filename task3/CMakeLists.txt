
option(ARM_BUILD "1" ON)
if (ARM_BUILD)
    add_definitions(-DARM_BUILD)
endif (ARM_BUILD)

option(TOOLCHAIN "2")
if (TOOLCHAIN)
    add_definitions(-DTOOLCHAIN)
endif (TOOLCHAIN)

option(CMAKE_INSTALL_PREFIX "3")
if (CMAKE_INSTALL_PREFIX)
    add_definitions(-DCMAKE_INSTALL_PREFIX)
endif (CMAKE_INSTALL_PREFIX)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)


cmake_minimum_required(VERSION 3.0)

project(SimpleLibrary)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)



add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)



target_link_libraries(MainLib buffer)

target_include_directories(buffer PUBLIC include)
target_include_directories(Main PUBLIC inclde)
target_include_directories(MainLib PUBLIC include)

install(TARGETS Main MainLib buffer
 RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin 
 LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
 
 
 install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)
 
 
       
#target_include_directories(Main PUBLIC include)
