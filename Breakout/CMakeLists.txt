cmake_minimum_required(VERSION 3.10)
project(Breakout)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Breakout main.cpp)

add_subdirectory(src/Engine)
target_link_libraries(Breakout Beetle)