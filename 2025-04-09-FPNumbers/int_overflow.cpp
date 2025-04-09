#include <cstdio>
#include <iostream>

int main(void)
{
    int a = 1;

    // TODO
    //while(true) {
    while(a > 0) {
        std::printf("%10d\n", a);
        a *= 2 ;
        //std::cin.get();
    }
    
    return 0;
}