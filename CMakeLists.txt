cmake_minimum_required(VERSION 3.10)

# set the project name
project(I2C)

set(CMAKE_CXX_FLAGS "-fPIC -g -pedantic -Wall -Wextra")

include_directories(src)

# Build the actual library
add_library(I2C SHARED src/i2c.h src/i2c.cpp)
