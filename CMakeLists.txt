cmake_minimum_required(VERSION 3.9)
project(dz1_techno_c)

add_subdirectory(console_app)
add_subdirectory(app_for_test)

add_custom_target(dz1_techno_c)
add_dependencies(dz1_techno_c test_app console)