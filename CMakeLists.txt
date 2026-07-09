cmake_minimum_required(VERSION 3.16)
project(Group6MusicSearch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Group6MusicSearch
        main.cpp
        DatasetProcessor.cpp
        HashTable.cpp)
