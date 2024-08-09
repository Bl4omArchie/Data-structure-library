#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/sysinfo.h>

void get_memory_info_file(double *total_ram, double *free_ram, double *available_ram) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture de /proc/meminfo");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MemTotal:", 9) == 0)
            *total_ram = atof(line + 9) / (1024.0 * 1024); // Convertir en GB
    
        else if (strncmp(line, "MemFree:", 8) == 0)
            *free_ram = atof(line + 8) / (1024.0 * 1024);  // Convertir en GB
        
        else if (strncmp(line, "MemAvailable:", 13) == 0) 
            *available_ram = atof(line + 13) / (1024.0 * 1024); // Convertir en GB
    
    }

    fclose(file);
}


void get_memory_info_struct() {
    struct sysinfo info;

    if (sysinfo(&info) == 0) {
        double total_ram = info.totalram / (1024.0 * 1024 * 1024); // Convertir en GB
        double free_ram = info.freeram / (1024.0 * 1024 * 1024);   // Convertir en GB

        printf("RAM struct totale: %.2f GB\n", total_ram);
        printf("RAM struct libre: %.2f GB\n", free_ram);
    } else {
        perror("Erreur lors de l'obtention des informations système");
    }
}

int main() {
    double total_ram = 0.0;
    double free_ram = 0.0;
    double available_ram = 0.0;

    get_memory_info_file(&total_ram, &free_ram, &available_ram);
    get_memory_info_struct();

    printf("RAM file totale: %.2f GB\n", total_ram);
    printf("RAM file libre: %.2f GB\n", free_ram);
    printf("RAM file libre totale: %.2f GB\n", available_ram);

    return 0;
}