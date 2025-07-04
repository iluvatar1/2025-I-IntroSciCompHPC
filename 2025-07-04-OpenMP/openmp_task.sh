#!/bin/bash
#
# SLURM script to run a job array with varying OMP_NUM_THREADS
#

# Standard Slurm directives:
#SBATCH --job-name=omp_test        # Job name
#SBATCH --output=omp_test_%A_%a.out # Standard output and error log (%A for job ID, %a for array task ID)
#SBATCH --error=omp_test_%A_%a.err  # Error log
#SBATCH --nodes=1                  # Request 1 node
#SBATCH --ntasks=1                 # Request 1 task (process)
#SBATCH --cpus-per-task=16         # Request 16 CPUs per task (max threads for OMP_NUM_THREADS)
#SBATCH --time=00:10:00            # Wall-clock time limit (HH:MM:SS)
#SBATCH --partition=16threads          # Specify a partition (e.g., debug, standard, short) - adjust as needed

# Job array directive:
#SBATCH --array=1-16               # Create a job array with tasks ID from 1 to 16

# Load necessary modules (if any, e.g., for compilers or specific libraries)
# module load gcc
# module load openmpi # If your application uses MPI alongside OpenMP

# Set OMP_NUM_THREADS based on the array task ID
export OMP_NUM_THREADS=$SLURM_ARRAY_TASK_ID

echo "---------------------------------------------------"
echo "Slurm Job ID: $SLURM_JOB_ID"
echo "Array Task ID: $SLURM_ARRAY_TASK_ID"
echo "Running on host: $(hostname)"
echo "Number of OMP_NUM_THREADS: $OMP_NUM_THREADS"
echo "---------------------------------------------------"

# Your OpenMP-enabled application command goes here.
# Replace './my_openmp_application' with the actual path to your executable.
# Make sure your application is compiled with OpenMP support (e.g., using -fopenmp with GCC).
./a.out 500000000 > openmp_times-${SLURM_ARRAY_TASK_ID}.txt

echo "Job finished for OMP_NUM_THREADS = $OMP_NUM_THREADS"
