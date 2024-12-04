#include "hardware.h"



hprof *create_hardware_profile() {
    hprof *hp = (hprof*)malloc(sizeof(hprof));
    
    hp->total_ram = get_ram();
    hp->available_ram = get_available_ram();
    hp->nb_procs = get_procs_nb();
    hp->os = get_os();
    hp->cpu_name = get_cpu();
    hp->architecture = get_architecture();
    hp->ext_sse = 0;
    hp->ext_sse2 = 0;
    hp->ext_avx = 0;
    hp->ext_avx2 = 0;
    
    return hp;
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

int display_specifications(hprof *hp) {
    if (hp == NULL)
        return -1;

    printf ("| OS : %s\n", hp->os);
    printf ("| Architecture : %s\n", hp->architecture);
    printf ("| CPU name: %s\n", hp->cpu_name);
    printf ("| CPU cores: %d\n", hp->nb_procs);
    printf ("| RAM: %.3f GB\n", hp->total_ram);
    printf ("| Available RAM: %.3f GB\n\n", hp->available_ram);
    return 1;
}