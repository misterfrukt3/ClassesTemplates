cmake_minimum_required(VERSION 3.23)

project(lab2)

set(CMAKE_CXX_STANDARD 17)


add_library(planet_lib STATIC
    PLanetLib/planet.cpp
)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME} planet_lib)
