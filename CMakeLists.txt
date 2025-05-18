cmake_minimum_required(VERSION 3.21)
project(Pr16 C)

set(CMAKE_C_STANDARD 99)

add_executable(Pr16 main.c
        CreateLoadStudents.h CreateLoadStudents.c
        StudentStruct.h StudentStruct.c
        ListStruct.h ListStruct.c
    )
