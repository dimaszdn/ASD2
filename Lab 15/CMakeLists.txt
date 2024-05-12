cmake_minimum_required(VERSION 3.27)
project(Lab_15)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_15 main.cpp
        inc/Graph.h
        inc/UserInput.h)
