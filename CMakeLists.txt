cmake_minimum_required(VERSION 3.8)
project(test)

find_package(Boost REQUIRED COMPONENTS system)

include_directories(Boost::boost)

add_executable(main main.cpp)
target_link_libraries(main Boost::system)

set(TARGETS main)

set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${TARGETS} PROPERTY CXX_EXTENSION OFF)
