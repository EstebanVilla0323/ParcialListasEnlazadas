cmake_minimum_required(VERSION 3.24)
project(Hotel)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hotel main.cpp Nodo.cpp Headers/Nodo.h Lista.cpp Headers/Lista.h Menu.cpp Headers/Menu.h)
