cmake_minimum_required(VERSION 3.5)
project(test)

find_package(Threads REQUIRED)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG(-std=c++1z HAVE_FLAG_CXX17)
if(HAVE_FLAG_CXX17)
  add_compile_options(-std=c++1z)
endif(HAVE_FLAG_CXX17)

add_executable(main main.cpp)
target_link_libraries(main Threads::Threads)

if(NOT HAVE_FLAG_CXX17)
  set_property(TARGET main PROPERTY CXX_STANDARD 14)
  set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)
  set_property(TARGET main PROPERTY CXX_EXTENSION OFF)
endif(NOT HAVE_FLAG_CXX17)

get_source_file_property(RESULT main.cpp COMPILE_FLAGS)
