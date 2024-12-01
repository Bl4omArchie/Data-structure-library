#include "report.h"


int create_log(bench *b, const char *filepath, const char *message) {
    FILE *file = fopen(filepath, "a");
    if (!file) {
        perror("Error while opening the log file");
        return -1;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "Positioning cursor failed");
        fclose(file);
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

int fill_report(bench *b, const char *filepath) {
    FILE *file = fopen(filepath, "a");
    if (!file) {
        perror("Error while opening the report file");
        return -1;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "Positioning cursor failed");
        fclose(file);
        return -1;
    }

    

    //TODO
}