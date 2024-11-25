#include "hardware.h"



hprof *create_hardware_profile() {
    hprof *h = (hprof*)malloc(sizeof(hprof*));

    h->total_ram = get_ram();
    h->available_ram = get_available_ram();
    h->nb_procs = get_procs_nb();
    h->architecture = get_architecture();

    return h;
}

int verify_cpu_extension_compatibility(hprof *hp) {
    if (hp == NULL)
        return -1;

    __builtin_cpu_init();
    hp->ext_sse = __builtin_cpu_supports("sse");
    hp->ext_sse2 = __builtin_cpu_supports("sse2");
    hp->ext_avx = __builtin_cpu_supports("avx");
    hp->ext_avx2 = __builtin_cpu_supports("avx2");
    return 1;
}

// TODO : https://stackoverflow.com/questions/48677575/does-gccs-builtin-cpu-supports-check-for-os-support
int verify_activated_extension(hprof *hp) {
    if (hp == NULL)
        return -1;
}