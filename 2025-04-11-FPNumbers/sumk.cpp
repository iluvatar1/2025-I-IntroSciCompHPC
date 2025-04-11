#include <iostream>
#include <cmath>

typedef float REAL;

// declaration
REAL sumk(int k);

int main(void)
{

    return 0;
}

// implementation
REAL sumk(int k)
{
    REAL suma = 0.0;
    for(int ii = 1; ii <= k; ii++) {
        suma += 0.1;
    }
    return std::fabs(k/10 - suma);
}
