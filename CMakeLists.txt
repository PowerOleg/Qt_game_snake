cmake_minimum_required(VERSION 3.5)

project(Snake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Snake main.cpp game.h game.cpp)

install(TARGETS Snake
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


find_package(Qt6 REQUIRED COMPONENTS Widgets)
target_link_libraries(Snake PRIVATE Qt6::Widgets)


