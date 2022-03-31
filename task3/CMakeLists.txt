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



find_library(MY_LIB NAMES buffer.h)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(buffer.h REQUIRED)
if(buffer.h_FOUND)
    include_directories(${mylib_INCLUDE_DIR})
endif

if (${ARM_BUILD})
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:${CMAKE_INSTALL_PREFIX}/lib")
    set(CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-gcc)
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
    install(TARGETS Main MainLib buffer
            RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin 
            LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
endif
cmake_minimum_required(VERSION 3.0)

project(SimpleLibrary)
include_directories(include)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)



add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)



target_link_libraries(MainLib buffer)

       
