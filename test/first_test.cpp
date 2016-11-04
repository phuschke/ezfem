#include "/usr/lib/openmpi/include/mpi.h"
#include <boost/mpi.hpp>
#include <iostream>




int main(int argc, char* argv[])
{
    boost::mpi::environment  env(argc, argv);
    boost::mpi::communicator world;
    std::cout << world.rank() << std::endl;



    int a = 1;
    boost::mpi::all_reduce(world,boost::mpi::inplace<int>(a), std::plus<int>());


    std::cout << "4 x 1 = " << a << std::endl;






    std::cout << "test successful" << std::endl;




}
