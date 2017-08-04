cmake_minimum_required(VERSION 3.5)
project(test)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main ${Boost_LIBRARIES} Threads::Threads)
set_property(TARGET main PROPERTY CXX_STANDARD 14)
