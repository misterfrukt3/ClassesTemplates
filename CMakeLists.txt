cmake_minimum_required(VERSION 3.10)

project(lab4)

add_executable(lab4 main.cpp)
target_include_directories(lab4 PRIVATE mystack)
set_target_properties(lab4 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
