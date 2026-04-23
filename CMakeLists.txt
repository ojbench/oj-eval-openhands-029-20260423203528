

cmake_minimum_required(VERSION 3.10)
project(MallocLab)

set(CMAKE_C_STANDARD 11)

add_executable(code code.c mm.c memlib.c)

