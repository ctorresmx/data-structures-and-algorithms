cmake_minimum_required(VERSION 3.17)
project(data_structures_and_algorithms C)

set(CMAKE_C_STANDARD 11)

#find_package(OpenMP REQUIRED)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")

add_executable(data_structures_and_algorithms main.c bubble_sort.c bubble_sort.h util.c util.h merge_sort.c merge_sort.h merge_sort_openmp.c merge_sort_openmp.h merge_sort_pthread.c merge_sort_pthread.h)

#target_link_libraries(data_structures_and_algorithms OpenMP::OpenMP_C)