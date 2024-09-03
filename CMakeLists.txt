cmake_minimum_required(VERSION 3.25)
project(SGI_STL)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SGI_STL
        allocator.h
        base.h
        list.h
        main.cpp
        type_traits.h
        vector.h)
