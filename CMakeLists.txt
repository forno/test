cmake_minimum_required(VERSION 3.1.2)
project(test)

add_executable(main main.cpp)
target_compile_options(main PRIVATE -std=c++1z)
