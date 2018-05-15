cmake_minimum_required(VERSION 3.8.2)
project(test)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "CXX standard version")
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "version required")
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "compiler extension")

find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Eigen3 REQUIRED)

set(Clang_WARN_OPTIONS
  -Weverything
  -Wno-c++98-compat
)
set(GNU_WARN_OPTIONS
  -Wall
  -Wextra
  -Wpedantic
  -Wchkp
  -Wdouble-promotion
  -Wnull-dereference
  -Wimplicit-fallthrough
  -Wmissing-include-dirs
  -Wswitch-enum
  -Wsync-nand
  -Wunused-parameter
  -Wuninitialized
  -Wstrict-overflow
  -Wsuggest-attribute=noreturn
  -Wsuggest-final-types
  -Wsuggest-final-methods
  -Walloc-zero
  -Walloca
  -Wduplicated-branches
  -Wduplicated-cond
  -Wtrampolines -Wfloat-equal -Wshadow
  -Wunsafe-loop-optimizations
  -Wcast-qual
  -Wconditionally-supported
  -Wconversion
  -Wzero-as-null-pointer-constant
  -Wdate-time
  -Wuseless-cast
  -Wsized-deallocation
  -Wlogical-op
  -Wmissing-declarations
  -Wnormalized
  -Wopenmp-simd
  -Wpacked
  -Wredundant-decls
  -Wrestrict
  -Winvalid-pch
  -Wvla
  -Wdisabled-optimization
  -Wstack-protector
  -Whsa
)

add_compile_options(
  "$<$<CXX_COMPILER_ID:Clang>:${Clang_WARN_OPTIONS}>"
  "$<$<CXX_COMPILER_ID:GNU>:${GNU_WARN_OPTIONS}>"
  $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(executable main.cpp)
target_link_libraries(executable Threads::Threads OpenSSL::SSL ${Boost_LIBRARIES})

add_custom_target(run ALL
  COMMAND executable < ${CMAKE_SOURCE_DIR}/input
  DEPENDS executable
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
