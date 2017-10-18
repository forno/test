cmake_minimum_required(VERSION 3.8)
project(test)

find_package(Boost REQUIRED COMPONENTS
  system regex)

include_directories(Boost::boost)
add_executable(execute main.cpp)
target_link_libraries(execute ${Boost_LIBRARIES})

set(TARGETS execute)

set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${TARGETS} PROPERTY CXX_EXTENSION OFF)

add_custom_target(run ALL
  COMMAND execute < input
  DEPENDS execute
  WORKING_DIRECTORY ${CMAKE_SOUCE_DIR})
