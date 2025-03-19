cmake_minimum_required(VERSION 3.23)

set(project "lab2")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp
        planet.cpp)


set(${project}_HEADERS
        planet.h)


set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST})


set_property(TARGET lab2 PROPERTY CXX_STANDARD 20)
