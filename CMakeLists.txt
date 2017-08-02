cmake_minimum_required(VERSION 3.1.3)
project(xmaho C CXX)

set(PROJECT_VER_MAJOR 0)
set(PROJECT_VER_MINOR 1)
set(PROJECT_VER_PATCH 0)
set(PROJECT_VER "${PROJECT_VER_MAJOR}.${PROJECT_VER_MINOR}.${PROJECT_VER_PATCH}")
set(PROJECT_APIVER "${PROJECT_VER_MAJOR}.${PROJECT_VER_MINOR}")

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS RelWithDebInfo RelWithDebInfo Release Debug MinSizeRel None)
if(NOT CMAKE_BUILD_TYPE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY VALUE RelWithDebInfo)
endif()

option(ENABLE_TEST "Enable test program building" OFF)
option(ENABLE_CXX17 "Enable C++17 support" OFF)

set(MY_DIR ${xmaho_SOURCE_DIR})

#set the default path for built executables to the "bin" directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

#set the default path for built libraries to the "lib" directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Winit-self -Wno-missing-field-initializers")

if(ENABLE_CXX17)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif()

# Add includes
include_directories(
  ${MY_DIR}/include
)

file(GLOB ICS3_HEADERS
  ${MY_DIR}/include/xmaho/*.hpp
  ${MY_DIR}/include/xmaho/*/*.hpp
)

if(ENABLE_TEST)
  set(GTEST_ROOT ${MY_DIR}/test/thirdparty/googletest/googletest)
  find_package(GTest REQUIRED)
  find_package(Threads)

  include_directories(${GTEST_INCLUDE_DIRS})
  add_executable(integral_test "test/string/split.cpp" "test/math/residue_system.cpp" "test/string/string.cpp")
  target_link_libraries(integral_test ${GTEST_BOTH_LIBRARIES})
  if(THREADS_HAVE_PTHREAD_ARG)
    target_compile_options(PUBLIC integral_test "-pthread")
  endif()
  if(CMAKE_THREAD_LIBS_INIT)
    target_link_libraries(integral_test "${CMAKE_THREAD_LIBS_INIT}")
  endif()

  enable_testing()
  add_test(IntegralTest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/integral_test)
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
