wget -O boost_1_61_0.tar.gz http://sourceforge.net/projects/boost/files/boost/1.61.0/boost_1_61_0.tar.gz/download
tar xfz boost_1_61_0.tar.gz
cd boost_1_61_0/
./bootstrap.sh --prefix=/usr/local
echo 'using mpi : <find-shared-library>mpic++ ;' >> project-config.jam
cat project-config.jam
sudo ./b2 --with-mpi --with-serialization -d0 -q install
cd ..
