FROM rockylinux:8

RUN yum -y update; yum clean all
RUN yum -y install git make gcc gcc-c++ gcc-gfortran cmake
RUN yum -y install wget unzip patch which file valgrind flex bison
RUN yum -y install dnf-plugins-core
RUN yum config-manager --set-enabled powertools
RUN yum -y install lapack-devel python3 findutils diffutils
RUN mkdir repo

RUN cd repo; \
    wget https://ftp.mcs.anl.gov/pub/petsc/release-snapshots/petsc-3.19.2.tar.gz; \
    tar -zxvf petsc-3.19.2.tar.gz; \
    mv petsc-3.19.2 petsc; \
    mkdir petsc-dist; \
    cd petsc; \
    ./configure configure --with-debug=0 --with-shared=0 --with-mpi=0 --with-fortran-bindings=0 --download-metis --download-mumps --with-mumps-serial=1 --prefix=/repo/petsc-dist; \
    make;\
    make install;

RUN cd repo; \
    wget https://boostorg.jfrog.io/artifactory/main/release/1.80.0/source/boost_1_80_0.tar.gz; \
    tar -zxvf boost_1_80_0.tar.gz; \
    cd ./boost_1_80_0; \
    sh bootstrap.sh --prefix=/usr/local/; \
    chmod a+x ./b2; \
    ./b2 install || true;
