cmake_minimum_required(VERSION 3.10)
project(InterceptingFilterPattern)

# Установка стандарта языка
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление исполняемого файла из исходных файлов
add_executable(intercepting_filter_demo
    ConceptualExample01.cpp
    Program.cpp
)

# Указание пути для заголовочных файлов
target_include_directories(intercepting_filter_demo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Подключение Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Создание тестов
enable_testing()

# Добавление исполняемого файла тестов
add_executable(intercepting_filter_tests
    ConceptualExample01.cpp
    tests.cpp
)

# Указание пути для заголовочных файлов
target_include_directories(intercepting_filter_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Линковка с библиотекой Google Test
target_link_libraries(intercepting_filter_tests gtest_main)

# Добавление тестов как цели сборки
add_test(NAME intercepting_filter_tests COMMAND intercepting_filter_tests)

