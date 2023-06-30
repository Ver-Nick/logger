cmake_minimum_required(VERSION 3.24)
project(logger)

set(CMAKE_CXX_STANDARD 20)

add_executable(logger main.cpp Message.cpp Message.h Logger.cpp Logger.h)
