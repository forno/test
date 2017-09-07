cmake_minimum_required(VERSION 3.8)
project(test)

add_executable(execute main.cpp)

set(TARGETS execute)

set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${TARGETS} PROPERTY CXX_EXTENSION OFF)

add_custom_target(run ALL
  COMMAND execute < input
  DEPENDS execute
  WORKING_DIRECTORY ${CMAKE_SOUCE_DIR})
