cmake_minimum_required(VERSION 3.9)
project(multi_thread C)

set(CMAKE_C_STANDARD 99)
SET(SRC_FILES_STATIC
        ../For_static_library/create_list.c
        ../For_static_library/print_list.c
        ../For_static_library/free_list.c
        ../For_static_library/compare_lists.c
        ../For_static_library/reverse_list.c
        )

add_library(lib_dinamic SHARED ${SRC_FILES_STATIC})
include_directories(../includes/lists.h)
add_executable(multi_thread ../For_static_library/main.c)
target_link_libraries(multi_thread lib_static)
#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)
#target_link_libraries(dz_2 Threads::Threads)