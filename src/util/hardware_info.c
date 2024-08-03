#include "util.h"


#include <sys/sysinfo.h>
#include <sys/resource.h>
#include <sys/time.h>

#include <sched.h>
#include <time.h>



/*

1 GiB = 1024 MiB
1 MiB = 1024 kB

So, 1 GiB = 1024 * 1024 kB = 1,048,576 kB.

7860156 kB ÷ 1,048,576 kB/GiB ≈ 7.5 GiB


-----------------------------------------------


1 Go = 1×1091×109 octets

La taille d'un nœud est de 24 octets.

How much nodes can be generated for 3GB:

3 * 10^9 / 24 = 125,000,000 nodes

*/


int get_procs_nb() {
    int nprocs = sysconf(_SC_NPROCESSORS_ONLN);
    if (nprocs == -1) 
        perror("sysconf");

    return nprocs;
}

double get_max_ram() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) return -1;

    char line[256];
    long max_ram = -1;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &max_ram) == 1) {
            max_ram *= 1024; // Convert from kB to bytes
            break;
        }
    }

    fclose(file);
    return max_ram / 1000000000.0;
}

double get_available_ram() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) return -1;

    char line[256];
    long available_ram = -1;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemAvailable: %ld kB", &available_ram) == 1) {
            available_ram *= 1024; // Convert from kB to bytes
            break;
        }
    }

    fclose(file);
    return available_ram / 1000000000.0;
}

void display_specifications() {
    printf ("*****************************\n");
    printf (" CPU cores: %d\n", get_procs_nb());
    printf (" RAM: %.4f GB\n", get_max_ram() );
    printf (" Available RAM: %.4f GB\n", get_available_ram() );
    printf ("*****************************\n\n");
}