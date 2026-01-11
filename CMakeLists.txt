cmake_minimum_required(VERSION 3.5)

project(Snake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем путь к твоему Qt5
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2-msvc2019_64-min")

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(Snake WIN32 main.cpp game.h game.cpp)

# Подключаем нужные модули
target_link_libraries(Snake PRIVATE Qt5::Widgets)

# Для установки (опционально)
install(TARGETS Snake
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})



