#include <iostream>
#include <cstdlib>

typedef double REAL;

int main(int argc, char **argv)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    int N = std::atoi(argv[1]);
    REAL one = 1.0, eps = 1.0;

    //TODO
    for (int ii = 0; ii < N; ++ii){
      eps /= 2.0;
      one = 1.0 + eps;
      std::cout << ii << "\t"
                << one << "\t"
                << eps << "\n";
    }

    return 0;
}