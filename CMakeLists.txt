cmake_minimum_required(VERSION 3.5)
project(test)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

include_directories(Boost::boost)

add_executable(main main.cpp)
target_link_libraries(main Boost::system Threads::Threads)

set(TARGETS main)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG(-std=c++1z HAVE_FLAG_CXX17)
if(HAVE_FLAG_CXX17)
  foreach(i IN LISTS TARGETS)
    target_compile_options(${i} PUBLIC -std=c++1z)
  endforeach(i IN LISTS TARGETS)
else(HAVE_FLAG_CXX17)
  set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD 14)
  set_property(TARGET ${TARGETS} PROPERTY CXX_STANDARD_REQUIRED ON)
  set_property(TARGET ${TARGETS} PROPERTY CXX_EXTENSION OFF)
endif(HAVE_FLAG_CXX17)
