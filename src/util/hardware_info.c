#include "util.h"


#include <sys/sysinfo.h>
#include <sched.h>



long get_available_ram() {
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
    return available_ram;
}


void display_specifications() {
    struct sysinfo sys_info;

    if (sysinfo(&sys_info) != 0)
        perror("sysinfo");

    long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
    if (nprocs == -1) 
        perror("sysconf");

    
    printf ("*****************************\n");
    printf (" CPU cores: %ld\n", nprocs);
    printf (" RAM: %ld\n", sys_info.totalram);
    printf (" Available RAM: %ld\n", sys_info.freeram);
    printf ("*****************************\n\n");
}