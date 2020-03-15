cmake_minimum_required(VERSION 3.9)
project(dz2_techno_c)

add_subdirectory(multi_thread_app)
add_subdirectory(single_thread_app)

add_custom_target(dz2_techno_c)
add_dependencies(dz2_techno_c single_thread multi_thread)