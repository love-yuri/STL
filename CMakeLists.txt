cmake_minimum_required(VERSION 3.25)
project(SGI_STL)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(${PROJECT_NAME}
  allocator.h
  base.h
  list.h
  type_traits.h
  vector.h

  main.cpp
)
