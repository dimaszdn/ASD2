cmake_minimum_required(VERSION 3.27)
project(Lab_11)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc/)

add_executable(Lab_11 main.cpp
        inc/UserInput.h
        inc/KnuthMorrisPratt.h)