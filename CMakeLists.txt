cmake_minimum_required(VERSION 3.26)
project(AVL_Tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVL_Tree main.cpp
        Tree.cpp
        Tree.h
        Node.cpp
        Node.h)
