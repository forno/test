cmake_minimum_required(VERSION 3.8)
project(test)

add_executable(main main.cpp)

set(TARGETS main)

set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${TARGETS} PROPERTY CXX_EXTENSION OFF)
