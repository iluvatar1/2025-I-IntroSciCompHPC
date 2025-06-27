#!/bin/bash -l
#SBATCH --job-name="testmulti"
# #SBATCH --account="HerrComp" # not used
#SBATCH --mail-type=ALL
#SBATCH --mail-user=wfoquendop@unal.edu.co
#SBATCH --time=01:00:00
#SBATCH --nodes=3
#SBATCH --ntasks-per-node=12
#SBATCH --cpus-per-task=1
#SBATCH --partition=12threads

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK


echo "Job ID: $SLURM_JOB_ID"
echo "Node: $(hostname)"
echo "CPUs: $SLURM_CPUS_ON_NODE"
echo "Dir: $SLURM_SUBMIT_DIR"

#stress -t 10 -c 1

