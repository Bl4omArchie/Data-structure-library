#include "hardware.h"



hprof *create_hardware_profile() {
    hprof *h = (hprof*)malloc(sizeof(hprof*));

    h->total_ram = get_ram();
    h->available_ram = get_available_ram();
    h->nb_procs = get_procs_nb();
    h->build = get_build();

    return h;
}