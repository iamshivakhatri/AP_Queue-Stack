cmake_minimum_required(VERSION 3.27)
project(khatri_shiva_prog2csc402)

set(CMAKE_CXX_STANDARD 17)

add_executable(khatri_shiva_prog2csc402 main.cpp
        Employee.h
        Employee.cpp
        myStack.h
        myStack.cpp
        myQueue.cpp)
