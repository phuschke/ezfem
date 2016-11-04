enable_testing()

set(test first_test)
add_executable(${test} ${test}.cpp)
target_link_libraries(first_test ${MPI_LIBRARIES} ${Boost_LIBRARIES})
set(MPIEXEC_NUMPROC_FLAG -np 4)
set(MPIEXEC mpirun)
add_test(NAME c_test_first_test COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} ${test})
