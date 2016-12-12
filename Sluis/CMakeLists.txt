# Miscellaneous settings.

cmake_minimum_required(VERSION 2.5)
project(Sluis)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# All source files required by executables.

file(GLOB Source_Files
		"*.h"
        "*.hpp"
        "*.c"
        "*.cpp")


# Executables to be build.

add_executable(Sluis Main.cpp ${Source_Files})
