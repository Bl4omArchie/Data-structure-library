#include "util.h"


#include <sys/sysinfo.h>
#include <sys/resource.h>
#include <sys/time.h>

#include <sched.h>
#include <string.h>
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

double get_ram() {
    struct sysinfo info;

    if (sysinfo(&info) == 0)
        return info.totalram / (1024.0 * 1024 * 1024); // Convertir en GB

    else {
        perror("Erreur lors de l'obtention des informations système");
        return -1;
    }
}

double get_available_ram() {
    double available_ram;

    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture de /proc/meminfo");
        return -1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MemAvailable:", 13) == 0) 
            available_ram = atof(line + 13) / (1024.0 * 1024); // Convertir en GB
    }

    fclose(file);
    return available_ram;
}

/*
void print_cpu_details() {
    if (!cpuinfo_initialize())
        fprintf(stderr, "Erreur lors de l'initialisation de cpuinfo.\n");
    
    printf ("*****************************\n");
    printf ("CPU %s\n", cpuinfo_get_package(0)->name);
    uint32_t logical_processors = cpuinfo_get_processors_count();
    printf("Nombre de processeurs logiques : %u\n", logical_processors);

    uint32_t physical_cores = cpuinfo_get_cores_count();
    printf("Nombre de coeurs physiques : %u\n", physical_cores);

    cpuinfo_deinitialize();
}
*/

void display_specifications() {
    printf ("*****************************\n");
    printf (" CPU cores: %d\n", get_procs_nb());
    printf (" RAM: %.3f GB\n", get_ram());
    printf (" Available RAM: %.3f GB\n", get_available_ram());
    printf ("*****************************\n\n");
}