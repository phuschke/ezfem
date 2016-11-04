#include "/usr/lib/openmpi/include/mpi.h"
#include <boost/mpi.hpp>
#include <iostream>




int main(int argc, char* argv[])
{
    boost::mpi::environment  env(argc, argv);
    boost::mpi::communicator world;
    std::cout << world.rank() << std::endl;
    std::cout << "test successful" << std::endl;



}
