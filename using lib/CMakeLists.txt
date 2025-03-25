# Минимальная версия CMake
cmake_minimum_required(VERSION 3.23)

# Название проекта
project(PlanetApp)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)


set(libplanet_lib.a)

# Создание исполняемого файла
add_executable(PlanetApp
    main.cpp
)

# Линковка статической библиотеки
target_link_libraries(PlanetApp
    ${LIBPLANET_LIBRARY}
)
