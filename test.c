#include <stdio.h>
#include <sys/time.h>


/*
for 100000 iteration
gcc      : 23.16s    
gcc -O3  :  4.27s
gcc avx2 :  4.02s

There is no difference :/
*/

int main() {
    const int n = 1e5;
    int a[n];
    volatile int s = 0;

    struct timeval start, end;

    gettimeofday(&start, NULL);
    for (int t = 0; t < 1000000; t++)
        for (int i = 0; i < n; i++)
            s += a[i];
    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    // Affichage
    printf("Elapsed time: %.4fs\n", elapsed);
    return 0;
}