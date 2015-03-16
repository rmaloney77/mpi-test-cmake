#include <stdio.h>
#include <mpi.h>


int main(int argc, char **argv) { 
	int process_rank;
	int world_process_count;

	MPI_Status status;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &world_process_count);

	MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);

	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;
	MPI_Get_processor_name(processor_name, &name_len);

	double time_start = MPI_Wtime();

	float check = process_rank + 1;

	while((MPI_Wtime() - time_start) < check);

	printf("Hello World from processor %s rank %d (of %d). Elapsed time is %f.\n",
			processor_name,
			process_rank,
			world_process_count,
			(MPI_Wtime() - time_start));
	
	MPI_Finalize();
}
