cmake_minimum_required(VERSION 3.9)
project(single_thread C)

set(CMAKE_C_STANDARD 99)
SET(SRC_FILES_STATIC
        ../For_static_library/create_list.c
        ../For_static_library/print_list.c
        ../For_static_library/free_list.c
        ../For_static_library/compare_lists.c
        ../For_static_library/reverse_list.c
        )
add_library(lib_static STATIC ${SRC_FILES_STATIC})
include_directories(../includes/lists.h)
add_executable(single_thread ../For_static_library/main.c)
target_link_libraries(single_thread lib_static)
