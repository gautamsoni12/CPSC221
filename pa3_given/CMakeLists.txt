cmake_minimum_required(VERSION 3.8)
project(pa3_given)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    diffall.sh
    in.png
    main.cpp
    Makefile
    png.cpp
    png.h
    quadtree.cpp
    quadtree.h
    quadtree_given.cpp
    quadtree_given.h
    rgbapixel.cpp
    rgbapixel.h
    soln_outCopy.png
    soln_outEtc.png
    soln_outHalf.png
    soln_outPruned.png
    soln_outRotated.png
    soln_pa3.out)

add_executable(pa3_given ${SOURCE_FILES})