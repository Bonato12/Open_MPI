// Reduce original, lo que hace este programa es enviar al proceso con pid = 0
// Las comunicaciones punto a punto son sincrona
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv){

    int my_rank;
    int num_procs;
    int num, prod;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    num = my_rank+1;

    MPI_Reduce(&num, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    if (my_rank == 0) 
        printf("Hola, soy el proceso %d y el FACTORIAL de %d es %d\n", my_rank, num_procs, prod);

    MPI_Finalize();

}