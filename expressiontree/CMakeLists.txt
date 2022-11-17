cmake_minimum_required(VERSION 3.23)
project(expressiontree)

set(CMAKE_CXX_STANDARD 14)

add_executable(expressiontree main.cpp expressiontree.h linkstack.h bintree.h)
