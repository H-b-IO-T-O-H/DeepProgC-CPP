cmake_minimum_required(VERSION 3.9)
project(dz_2 C CXX)
set(CMAKE_C_STANDARD 99)

SET(SRC_FILES_STATIC
        utils/free_func.c
        utils/print_array.c
        utils/create_threads.c
        utils/request_user_data.c
        utils/create_data_struct.c
        utils/create_and_fill_array.c
        For_static_library/compare_arrays.c
        )

SET(SRC_FILES_DYNAMIC
        utils/free_func.c
        utils/print_array.c
        utils/create_threads.c
        utils/request_user_data.c
        utils/create_data_struct.c
        utils/create_and_fill_array.c

        For_dynamic_library/cmp_arrays.c
        For_dynamic_library/fill_arrays.c
        For_dynamic_library/multi_thread_funcs.c)

SET(SRC_FILES_TESTS
        tests/main.cpp
        tests/Test.cpp)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include_directories(includes)

add_library(static STATIC ${SRC_FILES_STATIC})
add_library(dynamic SHARED ${SRC_FILES_DYNAMIC})

add_executable(single_thread For_static_library/main.c)
add_executable(multi_thread For_dynamic_library/main.c)
add_executable(gtest_test ${SRC_FILES_TESTS})

target_link_libraries(single_thread static)
target_link_libraries(multi_thread dynamic Threads::Threads)
target_link_libraries(gtest_test gtest dynamic pthread static)