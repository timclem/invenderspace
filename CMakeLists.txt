

cmake_minimum_required(VERSION 3.10)
project(TP5)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(TP5 main.cpp)
target_link_libraries(TP5 ${CONAN_LIBS})