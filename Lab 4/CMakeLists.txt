cmake_minimum_required(VERSION 3.27)
project(Lab_4)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_4 main.cpp
        inc/DFS.h
        inc/Func.h)