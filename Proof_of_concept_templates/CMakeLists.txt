# Miscellaneous settings.

cmake_minimum_required(VERSION 2.5)
project(Proof_of_concept_templates)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")


# All source files required by executables.

file(GLOB Source_Files
		"*.h"
        "*.hpp"
        "*.c"
        "*.cpp")


# Executables to be build.

add_executable(Proof_of_concept_templates main.cpp ${Source_Files})
