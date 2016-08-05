cmake_minimum_required (VERSION 2.8.11)
project (ezfem)

set(CMAKE_MACOSX_RPATH 1)
set(BUILD_SHARED_LIBS on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

add_subdirectory(examples)
add_subdirectory(fem)

add_executable(main main.cpp)
target_link_libraries (main fem)

