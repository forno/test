cmake_minimum_required(VERSION 3.5)
project(test)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(test_node main.cpp)
set_property(TARGET test_node PROPERTY CXX_STANDARD 14)
target_link_libraries(test_node ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
