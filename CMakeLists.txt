cmake_minimum_required (VERSION 3.2)
project (ezfem)

set(CMAKE_MACOSX_RPATH 1)
#set(BUILD_SHARED_LIBS on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 --coverage")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

find_package(Boost COMPONENTS mpi serialization REQUIRED)
#find_package(Boost REQUIRED)
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
include_directories(${Boost_INCLUDE_DIR})
set(Boost_USE_STATIC_LIBS ON)
message(STATUS "Boost root = ${BOOST_ROOT}")
message(STATUS "Boost version = ${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}.${Boost_SUBMINOR_VERSION}")
message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
message(STATUS "Boost_LIBRARY_DIRS = ${Boost_LIBRARY_DIRS}")
message(STATUS "Boost_MPI_FOUND =   ${Boost_MPI_FOUND}")
message(STATUS "Boost_MPI_LIBRARY = ${Boost_MPI_LIBRARY}")
message(STATUS "Boost_SERIALIZATION_FOUND = ${Boost_SERIALIZATION_FOUND}")
message(STATUS "Boost_SERIALIZATION_LIBRARY = ${Boost_SERIALIZATION_LIBRARY}")
message(STATUS "BOOST_INCLUDE_DIR = ${BOOST_INCLUDE_DIR}")
message(STATUS "BOOST_INCLUDE_DIRS = ${BOOST_INCLUDE_DIRS}")

add_subdirectory(examples)
add_subdirectory(fem)

add_executable(main main.cpp)
target_link_libraries (main fem)

add_subdirectory(test)
#test Environment
include(CTest)


# doxygen documentation
find_package(Doxygen REQUIRED)
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(DOXYGEN_INPUT_DIRECTORY "${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/documentation")
configure_file(${CMAKE_SOURCE_DIR}/documentation/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
add_custom_target(doxygen ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
