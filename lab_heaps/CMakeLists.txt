cmake_minimum_required(VERSION 3.8)
project(lab_heaps)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        coloredout.cpp
        coloredout.h
        heap.cpp
        heap.h
        printheap.cpp
        printtree.h
        random.h
        soln_testheap.out
        testheap.cpp)

add_executable(lab_heaps ${SOURCE_FILES})