cmake_minimum_required(VERSION 3.25)
project(SGI_STL)

set(CMAKE_CXX_STANDARD 26)

include_directories(.)

add_executable(${PROJECT_NAME}
  allocator.hpp
  base.hpp
  list.hpp
  type_traits.hpp
  vector.hpp

  main.cpp
)
