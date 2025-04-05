cmake_minimum_required(VERSION 3.16)
project(sda_example)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(sda_example ${PROJECT_SOURCE_DIR}/example.c ${PROJECT_SOURCE_DIR}/object.c)