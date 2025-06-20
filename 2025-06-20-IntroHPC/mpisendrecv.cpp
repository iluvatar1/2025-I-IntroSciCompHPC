#include <mpi.h>
#include <iostream>

void send_recv(int pid, int np);

int main(int argc, char** argv)
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int np;
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    // Get the rank of the process
    int pid;
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    send_recv(pid, np);

    
    // Finalize the MPI environment.
    MPI_Finalize();
}

void send_recv(int pid, int np)
{
    int val = 0;
    if (0 == pid) {
        // send
        val = 100; 
        MPI_Send(&val, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else {
        int buf;
        // recv
        MPI_Recv(&buf, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // print
        printf("Received %d from %d, I am %d (my vl =%d)\n", buf, 0, pid, val);
    }
}
