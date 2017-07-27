cmake_minimum_required(VERSION 3.5)
project(test)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ~/ws/prog/cpp-netlib/build)
find_package(cppnetlib 0.12.0 REQUIRED)
include_directories(${CPPNETLIB_INCLUDE_DIRS} ~/ws/prog/ab_connector/include)

add_executable(test_node main.cpp)
set_property(TARGET test_node PROPERTY CXX_STANDARD 14)
target_link_libraries(test_node ${CPPNETLIB_LIBRARIES})
