cmake_minimum_required(VERSION 3.10)
project(compi3)

set(CMAKE_CXX_STANDARD 98)

add_executable(compi3 main.cpp output.cpp output.hpp symtable.cpp symtable.h attributes.h scanner.lex parser.ypp)