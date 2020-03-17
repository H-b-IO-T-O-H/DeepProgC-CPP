cmake_minimum_required(VERSION 3.9)
project(single_thread C)

set(CMAKE_C_STANDARD 99)
SET(SRC_FILES_STATIC
        ../../utils/free_func.c
        ../../utils/create_array.c
        ../../utils/print_array.c
        ../../utils/request_user_data.c
        ../compare_arrays.c
        )
add_library(lib_static STATIC ${SRC_FILES_STATIC})
include_directories(../../includes/arrays.h)
add_executable(single_thread ../main.c)
target_link_libraries(single_thread lib_static)
