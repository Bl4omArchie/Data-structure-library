#ifndef HARDWARE_H
#define HARDWARE_H


#include <sys/sysinfo.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>
#include <string.h>
#include <time.h>

#include "report.h"


typedef struct _hardware_profile {
    double total_ram;
    double available_ram;
    int nb_procs;
    const char *build;
} hprof;


int get_procs_nb();
double get_ram();
double get_available_ram();
const char *get_build();

hprof *create_hardware_profile();
void display_specifications();


#endif