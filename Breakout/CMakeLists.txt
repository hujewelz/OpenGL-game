cmake_minimum_required(VERSION 3.10)
project(Breakout)

set(CMAKE_CXX_STATNARD 11)

add_executable(Breakout main.cpp)

add_subdirectory(lib/glapp)
add_subdirectory(lib/image)
target_link_libraries(Breakout glapp image)