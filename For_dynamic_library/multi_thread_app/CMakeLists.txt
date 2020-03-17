cmake_minimum_required(VERSION 3.9)
project(multi_thread C)

set(CMAKE_C_STANDARD 99)
SET(SRC_FILES_DYNAMIC
        ../../utils/free_func.c
        ../../utils/print_array.c
        ../../utils/create_array.c
        ../../utils/request_user_data.c
        ../main.c
        ../fill_arrays.c
        ../create_threads.c
        ../multi_thread_funcs.c
        ../cmp_arrays.c)

add_library(lib_dynamic SHARED ${SRC_FILES_DYNAMIC})
include_directories(../../includes/arrays.h)
add_executable(multi_thread ../main.c)
target_link_libraries(multi_thread lib_dynamic)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(multi_thread Threads::Threads)