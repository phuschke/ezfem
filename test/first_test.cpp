#include "/usr/lib/openmpi/include/mpi.h"
#include <boost/mpi.hpp>
#include <iostream>

#include <vector>
#include <eigen3/Eigen/Dense>


int main(int argc, char* argv[])
{
    boost::mpi::environment  env(argc, argv);
    boost::mpi::communicator world;
    std::cout << world.rank() << std::endl;



    int a = 1;
    boost::mpi::all_reduce(world,boost::mpi::inplace<int>(a), std::plus<int>());


    std::cout << "4 x 1 = " << a << std::endl;

    std::vector<int> recvCount;
    recvCount.push_back(1);
    recvCount.push_back(2);
    recvCount.push_back(1);
    recvCount.push_back(0);

    std::vector<int> displ;
    displ.push_back(0);
    displ.push_back(1);
    displ.push_back(3);
    displ.push_back(4);


    Eigen::VectorXd vector;
    vector.setConstant(3, world.rank());

    Eigen::VectorXd vectorGlobal;
    vectorGlobal.setZero(6);

    std::cout << vector << std::endl;

    world.barrier();

    MPI_Allgatherv(vector.data(),
                   vector.size(),
                   MPI_DOUBLE,
                   vectorGlobal.data(),
                   recvCount.data(),
                   displ.data(),
                   MPI_DOUBLE,
                   MPI_COMM_WORLD);


    if (world.rank()== 0)
        std::cout << vectorGlobal << std::endl;


    std::cout << "test successful" << std::endl;




}
