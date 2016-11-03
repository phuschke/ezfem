cmake_minimum_required (VERSION 3.2)
project (ezfem)

set(CMAKE_MACOSX_RPATH 1)
set(BUILD_SHARED_LIBS on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

find_package(Boost COMPONENTS mpi REQUIRED)
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})


add_subdirectory(examples)
add_subdirectory(fem)

add_executable(main main.cpp)
target_link_libraries (main fem)

add_subdirectory(test)
#test Environment
include(CTest)
