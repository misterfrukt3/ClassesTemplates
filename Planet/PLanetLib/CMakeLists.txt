cmake_minimum_required(VERSION 3.23)
project(libplanet)

# Создание статической библиотеки
add_library(planet STATIC planet.cpp)
