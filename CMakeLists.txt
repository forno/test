cmake_minimum_required(VERSION 2.8.12.2)
project(xmaho C CXX)

set(PROJECT_VER_MAJOR 0)
set(PROJECT_VER_MINOR 1)
set(PROJECT_VER_PATCH 0)
set(PROJECT_VER "${PROJECT_VER_MAJOR}.${PROJECT_VER_MINOR}.${PROJECT_VER_PATCH}")
set(PROJECT_APIVER "${PROJECT_VER_MAJOR}.${PROJECT_VER_MINOR}")

if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose: RelWithDebInfo Release Debug MinSizeRel None")
endif()

option(BUILD_SHARED_LIBS "Build shared (ON) or static (OFF) libraries" OFF)
option(ENABLE_TEST "Enable test program building" OFF)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(MY_DIR ${xmaho_SOURCE_DIR})

#set the default path for built executables to the "bin" directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

#set the default path for built libraries to the "lib" directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Add includes
include_directories(
  ${MY_DIR}/include
)

file(GLOB ICS3_HEADERS
  ${MY_DIR}/include/xmaho/*.hpp
  ${MY_DIR}/include/xmaho/*/*.hpp
)

if(ENABLE_TEST)
  set(GTEST_ROOT ${MY_DIR}/thirdparty/googletest/googletest)
  find_package(GTest REQUIRED)
  find_package(Threads)

  include_directories(${GTEST_INCLUDE_DIRS})
  if(THREADS_HAVE_PTHREAD_ARG)
  endif()
  if(CMAKE_THREAD_LIBS_INIT)
  endif()

  enable_testing()
endif()

install(DIRECTORY "${MY_DIR}/include/${PROJECT_NAME}" DESTINATION include)

get_cmake_property(vars VARIABLES)
message(STATUS "Feature list:")
foreach(var ${vars})
  if(var MATCHES ^HAVE_)
    string(REPLACE HAVE_ "" feature ${var})
    message(STATUS "  ${feature}    ${${var}}")
  endif()
endforeach()
