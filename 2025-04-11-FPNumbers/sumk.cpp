#include <iostream>
#include <cmath>

typedef float REAL;

// declaration
REAL sumk(int k);

int main(void)
{
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    std::cout << sumk(1) << "\n";

    return 0;
}

// implementation
REAL sumk(int k)
{
    REAL suma = 0.0;
    for(int ii = 1; ii <= k; ii++) {
        suma += 0.1;
    }
    REAL aux = k/10.0;
    return std::fabs(aux - suma);
}
