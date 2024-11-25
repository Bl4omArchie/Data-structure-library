#ifndef HARDWARE_H
#define HARDWARE_H


#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct _hardware_profile {
    double total_ram;           // Total RAM of the current computer
    double available_ram;       // Total RAM available
    int nb_procs;               // Number of processor of the cpu
    const char *architecture;   // Computer architecture
    int ext_sse;                // cpu extension sse
    int ext_sse2;               // cpu extension sse2
    int ext_avx;                // cpu extension avx
    int ext_avx2;               // cpu extension avx2
} hprof;


int get_procs_nb();
double get_ram();
double get_available_ram();
const char *get_cpu();
const char *get_architecture();
void display_specifications();


hprof *create_hardware_profile();
int verify_cpu_extension_compatibility(hprof *hp);
int verify_activated_extension(hprof *hp);

#endif