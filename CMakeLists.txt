cmake_minimum_required(VERSION 2.8)

project(mpi-test)

# Require MPI for this project:
find_package(MPI REQUIRED)
include_directories(${MPI_C_INCLUDE_PATH})
add_executable(mpi-test main.c)
target_link_libraries(mpi-test ${MPI_LIBRARIES})
