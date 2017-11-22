cmake_minimum_required(VERSION 3.8)
project(test)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "CXX standard version")
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "version required")
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "compiler extension")

find_package(Boost REQUIRED COMPONENTS
  system regex)

include_directories(Boost::boost)
add_executable(execute main.cpp)
target_link_libraries(execute Boost::system Boost::regex)

add_custom_target(run ALL
  COMMAND execute < input
  DEPENDS execute
  WORKING_DIRECTORY ${CMAKE_SOUCE_DIR})
