

cmake_minimum_required(VERSION 3.10)
project(invenderspace)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(invenderspace space.cpp Vaisseau.cpp Vaisseau.h)
target_link_libraries(invenderspace ${CONAN_LIBS})