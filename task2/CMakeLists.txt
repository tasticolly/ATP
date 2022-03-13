cmake_minimum_required(VERSION 3.0)
project(my_proj)


add_custom_command( 
  OUTPUT ${PROJECT_SOURCE_DIR}/A/index.h
  COMMAND python3 ${PROJECT_SOURCE_DIR}/A/prepearing.py
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A/
  DEPENDS ${PROJECT_SOURCE_DIR}/A/prepearing.py
)

include_directories(${PROJECT_SOURCE_DIR})

set(HEADERS A/index.h C/main.h)
set(SOURCES C/main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_executable(C ${SOURCES} ${HEADERS})
add_custom_target(RunGenerator DEPENDS ${PROJECT_SOURCE_DIR}/A/index.h)
add_dependencies( C RunGenerator )
add_subdirectory(B)
target_link_libraries(C libr)

