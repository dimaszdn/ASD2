cmake_minimum_required(VERSION 3.27)
project(Lab_2)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_2 main.cpp
        inc/BFS.h
        inc/Func.h)
