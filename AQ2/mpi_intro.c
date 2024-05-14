#include "mpi.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char message[20];
    int i, rank, size, type=99;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // printf("Hello world\n");

    if (!rank)
    {
        strcpy(message, "hello world");
        for (int i = 1; i<size; i++)
        {
            MPI_Send(message, 12, MPI_CHAR, i, type, MPI_COMM_WORLD);
        }
    }
    else
        MPI_Recv(message, 12, MPI_CHAR, 0, type, MPI_COMM_WORLD, &status);
        
    printf("Message from node=%d : %.13s\n", rank, message);
    MPI_Finalize();
}