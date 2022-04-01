add_library(buffer SHARED buffer.cpp)
install(TARGET buffer 
LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib})
