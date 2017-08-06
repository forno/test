cmake_minimum_required(VERSION 3.5)
project(test)

find_package(Threads REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main Threads::Threads)
add_executable(test1 main.cpp)
target_link_libraries(test1 Threads::Threads)
add_executable(test2 main.cpp)
target_link_libraries(test2 Threads::Threads)

set(TARGETS main test1 test2)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG(-std=c++1z HAVE_FLAG_CXX17)
if(HAVE_FLAG_CXX17)
  foreach(i IN LISTS TARGETS)
    target_compile_options(${i} PUBLIC -std=c++17)
  endforeach(i IN LISTS TARGETS)
else(HAVE_FLAG_CXX17)
  set_property(TARGET main PROPERTY CXX_STANDARD 14)
  set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)
  set_property(TARGET main PROPERTY CXX_EXTENSION OFF)
endif(HAVE_FLAG_CXX17)

get_source_file_property(RESULT main.cpp COMPILE_FLAGS)
