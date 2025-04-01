cmake_minimum_required(VERSION 3.23)
project(BookApp)

set(CMAKE_CXX_STANDARD 17)

# Путь к статической библиотеке
set(LIBBOOK_LIBRARY ${CMAKE_SOURCE_DIR}/libBook.a)

# Указываем путь к заголовочному файлу
include_directories(Book.h)

# Проверка существования библиотеки
if (NOT EXISTS ${LIBBOOK_LIBRARY})
    message(FATAL_ERROR "Библиотека ${LIBBOOK_LIBRARY} не найдена!")
endif()

# Создание исполняемого файла
add_executable(BookApp main.cpp)

# Линковка статической библиотеки
target_link_libraries(BookApp ${LIBBOOK_LIBRARY})
