cmake_minimum_required(VERSION 3.10)
project(InterceptingFilterPattern)

# Установка стандарта языка
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление исполняемого файла из исходных файлов
add_executable(intercepting_filter_demo
    ConceptualExample01.cpp
    ConceptualExample02.cpp
    Program.cpp
)

# Указание пути для заголовочных файлов
target_include_directories(intercepting_filter_demo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

