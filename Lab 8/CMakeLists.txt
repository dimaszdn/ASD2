cmake_minimum_required(VERSION 3.27)
project(Lab_8)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_8 main.cpp
        inc/UserInput.h
        inc/Dijkstra.h)
