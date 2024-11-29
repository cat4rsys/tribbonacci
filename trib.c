#include <stdio.h>
#include <stdlib.h>

/*
    computational complexity of native tribbonachi
    T(n) = C + T(n-1) + T(n-2) + T(n-3) | const will disappear
    e^an = e^an( e^(-a) + e^(-2a) + e^(-3a) )
    e^(-a) = x
    x(x^2 + x + 1) = 1
    x = 0,543689
    => T(n) = 1 * 1,8393 ^ n = 1,8393 ^ n
 */

int trib1(long n)
{
    switch (n) {
        case 0: return 0;
        case 1: return 0;
        case 2: return 1;
        default: return trib1(n-1) + trib1(n-2) + trib1(n-3);
    }
}

int _trib2(long n, int a, int b, int c)
{
    return n ? _trib2(n-1, a+b+c, a, b): c;
}

int trib2(long n)
{
    return _trib2(n, 1, 0, 0); // 1 0 0
}

int main(const int argc, const char * argv[]) {
    if (argc != 1) return -fprintf(stderr, "Error input\n");
    else {
        FILE * outputFile = fopen("data.dat", "w");

        for (long a = 0; a < 2000; a++)
            fprintf(outputFile, "%ld %d\n", a, trib2(a));

        fclose(outputFile);
    }
}
