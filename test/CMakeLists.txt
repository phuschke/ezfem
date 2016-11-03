enable_testing()
add_executable(first_test first_test.cpp ${MPI_C++_INCLUDE_PATH})
target_link_libraries(first_test ${MPI_LIBRARIES} ${Boost_LIBRARIES})
add_test(c_test_first_test first_test)
