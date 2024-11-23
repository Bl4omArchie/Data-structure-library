#include "benchmark.h"


int create_log(bench *b, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Erreur d'ouverture du fichier log");
        return -1;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] : ", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    fprintf(file, "%s\n", message);
    fprintf(file, "CPU time : %f\n", b->cpu_time);
    fprintf(file, "RAM used : %f\n", b->ram);
    fprintf(file, "Total time : %f\n", b->time);

    fprintf(file, "\n");
    fclose(file);
    return 1;
}