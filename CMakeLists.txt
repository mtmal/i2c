cmake_minimum_required(VERSION 3.10)

# set the project name
project(I2C)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-fPIC -g -pedantic -Wall -Wextra")

if(LOG) 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOG=1")
endif()

include_directories(src)

# Build the actual library
add_library(I2C SHARED src/I2C.h src/I2C.cpp)