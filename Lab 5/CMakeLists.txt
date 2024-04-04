cmake_minimum_required(VERSION 3.27)
project(Lab_5)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_5 main.cpp
        inc/Graph.h)
