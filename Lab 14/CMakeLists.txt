cmake_minimum_required(VERSION 3.27)
project(Lab_14)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_14 main.cpp
            inc/UserInput.h
        inc/RabinKarp.h)
