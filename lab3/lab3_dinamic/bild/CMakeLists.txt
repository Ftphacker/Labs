cmake_minimum_required(VERSION 2.8.8)
project(three)
add_library(lab_lib ../lab3_din.h ../cards.cpp ../function.cpp)
add_executable(main ../main.cpp)
target_link_libraries(main lab_lib)

