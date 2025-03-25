cmake_minimum_required(VERSION 3.23)
project(PlanetApp)

set(CMAKE_CXX_STANDARD 17)

# Путь к статической библиотеке
set(LIBPLANET_LIBRARY ${CMAKE_SOURCE_DIR}/libplanet.a)

# Указываем путь к заголовочному файлу
include_directories(planet.h)

# Проверка существования библиотеки
if (NOT EXISTS ${LIBPLANET_LIBRARY})
    message(FATAL_ERROR "Библиотека ${LIBPLANET_LIBRARY} не найдена!")
endif()

# Создание исполняемого файла
add_executable(PlanetApp main.cpp)

# Линковка статической библиотеки
target_link_libraries(PlanetApp ${LIBPLANET_LIBRARY})
