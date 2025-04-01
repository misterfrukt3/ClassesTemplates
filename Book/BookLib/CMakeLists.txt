cmake_minimum_required(VERSION 3.23)
project(libBook)

# Создание статической библиотеки
add_library(Book STATIC Book.cpp)
