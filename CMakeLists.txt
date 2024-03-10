cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

project(arraylist C)

set(CMAKE_C_STANDARD 23)

add_library(arraylist STATIC arraylist-runtime.c)
