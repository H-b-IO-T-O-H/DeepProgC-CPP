cmake_minimum_required(VERSION 3.9)
project(single_thread C)

set(CMAKE_C_STANDARD 99)
SET(SRC_FILES_STATIC
        ../For_static_library/create_array.c
        ../For_static_library/print_array.c
        ../For_static_library/compare_arrays.c
        )
add_library(lib_static STATIC ${SRC_FILES_STATIC})
include_directories(../includes/arrays.h)
add_executable(single_thread ../For_static_library/main.c)
target_link_libraries(single_thread lib_static)
