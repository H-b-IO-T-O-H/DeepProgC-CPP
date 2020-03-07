cmake_minimum_required(VERSION 3.9.2)
project(console C)

set(CMAKE_C_STANDARD 99)

set(HEADER_SOURCES ../Project/include/buildings.h ../Project/include/test.h)
set(CLIENT_SOURCES ../Project/srcs/get_build_info.c  ../Project/srcs/purpose.c ../Project/srcs/location.c ../Project/srcs/utils.c ../Project/tests/unit_test.c ../Project/srcs/console_app.c)

add_executable(console ${HEADER_SOURCES} ${CLIENT_SOURCES})