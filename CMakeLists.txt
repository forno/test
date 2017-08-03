cmake_minimum_required(VERSION 3.5)
project(test)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(client client.cpp)
target_link_libraries(client ${Boost_LIBRARIES} Threads::Threads)
add_executable(server server.cpp)
target_link_libraries(server ${Boost_LIBRARIES} Threads::Threads)
set_property(TARGET client server PROPERTY CXX_STANDARD 14)
