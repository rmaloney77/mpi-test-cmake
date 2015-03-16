cmake_minimum_required(VERSION 2.8)

project(mpich2-test)

# Require MPI for this project:
find_package(MPI REQUIRED)
include_directories(MPI_C_INCLUDE_PATH)
add_executable(mpich2-test main.c)
target_link_libraries(mpich2-test ${MPI_LIBRARIES})
