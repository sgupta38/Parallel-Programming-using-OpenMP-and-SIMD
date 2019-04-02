cmake_minimum_required(VERSION 3.13)
project(assignment-2-sgupta38)
set(CMAKE_CXX_STANDARD 11)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(
        sequential
        common.h
        Csequential.cpp
        Csequential.h
        main.cpp
        )