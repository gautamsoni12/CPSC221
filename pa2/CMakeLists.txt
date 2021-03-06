cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

# Put the project command before everything else.  At minimum, it
# reset my compiler flags; probably other things as well!
project ("pa2")

# Helps with compiling on Cygwin. No effect otherwise.
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

# Enable C++11.
add_definitions("-std=c++11")

# Set aggressive warning flags for compilation.
# From http://stackoverflow.com/questions/2368811/how-to-set-warning-level-in-cmake
if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

# To find my libraries 
set(MY_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH
        "Base directory of which all libraries are subdirectories.")
set(GMOCK_DIR "${MY_LIB_DIR}/gmock-1.7.0" CACHE PATH
        "The path to the GoogleMock test framework.")
set(CPPLINT "${MY_LIB_DIR}/cpplint.py" CACHE PATH
        "The path to the C++ lint style checker.")

enable_testing()


# To make Google Test testing work correctly in MSVC, per
# http://johnlamp.net/cmake-tutorial-4-libraries-and-subdirectories.html
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # force this option to ON so that Google Test will use /MD instead
    # of /MT /MD is now the default for Visual Studio, so it should be
    # our default, too 
    option(gtest_force_shared_crt "Use shared (DLL) run-time lib even when Google Test is built as static lib."  ON)
endif()



# Main executable for the project.
add_executable(
        partners.txt
        stack.cpp
        queue.cpp
        arrayclass.cpp
        cmake-build-debug
        stack.h
        queueprivate.h
        queue.h
        Makefile
        interpretertest.cpp
        interpretersecretfunctions.h
        interpreterprivate.h
        interpreter.h
        containertests.cpp
        arrayclassprivate.h
        arrayclass.h
        stackprivate.h)




# Other things that would be handy to do in here but haven't been set
# up:
#
# + Check style on everything with cpplint.py
# + Run valgrind
# + Do racka_bracka testing vs. the *.out.txt files.