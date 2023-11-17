cmake_minimum_required(VERSION 3.26)
project(ProyectoProgra2Final)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProyectoProgra2Final main.cpp
        Hash.cpp
        Hash.h
        Key.cpp
        Key.h
        MenuYCarga.cpp
        MenuYCarga.h
        DoublyLinkedList.cpp
        DoublyLinkedList.h)
