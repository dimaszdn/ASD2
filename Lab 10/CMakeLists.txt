cmake_minimum_required(VERSION 3.27)
project(Lab_10)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_10 main.cpp
        inc/Graph.h
        inc/UserInput.h)

file(COPY "files" DESTINATION /)