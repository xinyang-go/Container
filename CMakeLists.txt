cmake_minimum_required(VERSION 3.15)
project(Container)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall)
add_compile_options(-O2)

add_executable(example example.cpp)
