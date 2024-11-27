#include "hardware.h"

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

const char *get_cpu() {
    __builtin_cpu_init();

    if (__builtin_cpu_is("amd"))
        return "amd";
    else if (__builtin_cpu_is("intel"))
        return "intel";
    else if (__builtin_cpu_is("atom"))
        return "atom";
    else if (__builtin_cpu_is("slm"))
        return "slm";
    else if (__builtin_cpu_is("core2"))
        return "core2";
    else if (__builtin_cpu_is("corei7"))
        return "intel core i7";
    
    else if (__builtin_cpu_is("nehalem"))
        return "intel Core i7 Nehalem";
    
    else if (__builtin_cpu_is("westmere"))
        return "intel Core i7 Westmere";
    
    else if (__builtin_cpu_is("sandybridge"))
        return "intel Core i7 Sandy Bridge";
    
    else if (__builtin_cpu_is("ivybridge"))
        return "intel Core i7 Ivy Bridge";
    else
        return "unsupported";
}

const char *get_os() {
    #if defined(_WIN32)
        return "windows";
    #elif defined(_WIN64)
        return "windows";
    #elif defined(__linux__)
        return "linux";
    #elif defined(__APPLE__)
        return "macOS";
    #elif defined(__FreeBSD__)
        return "freeBSD";
    #elif defined(__sun)
        return "solaris";  
    #else
        return "unsupported";
    #endif
}   

// Source : https://stackoverflow.com/a/66249936
const char *get_architecture() { //Get current architecture, detectx nearly every architecture. Coded by Freak
    #if defined(__x86_64__) || defined(_M_X64)
    return "x86_64";
    #elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
    return "x86_32";
    #elif defined(__ARM_ARCH_2__)
    return "ARM2";
    #elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
    return "ARM3";
    #elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
    return "ARM4T";
    #elif defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_)
    return "ARM5"
    #elif defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_)
    return "ARM6T2";
    #elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
    return "ARM6";
    #elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
    return "ARM7";
    #elif defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
    return "ARM7A";
    #elif defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
    return "ARM7R";
    #elif defined(__ARM_ARCH_7M__)
    return "ARM7M";
    #elif defined(__ARM_ARCH_7S__)
    return "ARM7S";
    #elif defined(__aarch64__) || defined(_M_ARM64)
    return "ARM64";
    #elif defined(mips) || defined(__mips__) || defined(__mips)
    return "MIPS";
    #elif defined(__sh__)
    return "SUPERH";
    #elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
    return "POWERPC";
    #elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
    return "POWERPC64";
    #elif defined(__sparc__) || defined(__sparc)
    return "SPARC";
    #elif defined(__m68k__)
    return "M68K";
    #else
    return "UNKNOWN";
    #endif
}