cmake_minimum_required(VERSION 3.10)
project(NumberSystemAdder)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходные файлы
set(SOURCES
    src/main.cpp
    src/NumberSystemConverter.cpp
    src/InputParser.cpp
    src/FileHandler.cpp
)

# Заголовочные файлы
set(HEADERS
    include/NumberSystemConverter.h
    include/InputParser.h
    include/FileHandler.h
)

# Добавляем возможность запуска тестов
enable_testing()

# Добавляем тестовый запуск
add_test(NAME TestAddition COMMAND NumberSystemAdder ../test/input.txt output.txt)

# Создаем исполняемый файл
add_executable(NumberSystemAdder ${SOURCES} ${HEADERS})

# Указываем пути к заголовочным файлам
target_include_directories(NumberSystemAdder PRIVATE include)

endif()