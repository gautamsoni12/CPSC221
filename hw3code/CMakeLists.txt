cmake_minimum_required(VERSION 3.8)
project(hw3code)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        lucky.cpp
        lucky.h
        Makefile)

add_executable(hw3code ${SOURCE_FILES})