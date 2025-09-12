#include <stdio.h>

long long fibbRek(long long num)
{
    if (num == 1)
        return 1;
    if (num == 0)
        return 0;

    return fibbRek(num - 1) + fibbRek(num - 2);
}

long long fibbIter(long long num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;

    long long current = 1;
    long long last = 0;

    num -= 2;

    while (num-- >= 0)
    {
        long long temp = current;
        current = current + last;
        last = temp;
    }
    return current;
}

long long main()
{
    // for (long long i = 2; i < 40; i++)
    // {
    //     prlong longf("Iteration %3d: %10d, ", i, fibbRek(i));
    //     prlong longf("Verhaeltnis: %.20lf\n", (double)fibbRek(i) / fibbRek(i - 1));
    // }

    long long last = 1;
    for (long long i = 2; i < 120; i++)
    {
        long long fibb = fibbIter(i);
        printf("Iteration %3lld: %10lld, Verhaeltnis: %.20lf\n", i, fibb, (double) fibb / last);
        last = fibb;
    }

    return 0;
}