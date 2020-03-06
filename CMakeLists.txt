cmake_minimum_required(VERSION 3.9.2)
project(techno_dz1 C)

set(CMAKE_C_STANDARD 99)

add_executable(techno_dz1 Project/srcs/main.c Project/srcs/get_build_info.c Project/include/buildings.h Project/srcs/purpose.c Project/srcs/location.c Project/srcs/print_struct.c Project/tests/unit_test.c)