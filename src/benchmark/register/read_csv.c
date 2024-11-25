#include "report.h"


#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 10
#define PATH_MAX 100


void read_csv(const char *path_file) {
    char abs_path[PATH_MAX];
    if (realpath(path_file, abs_path) == NULL) {
        perror("Error resolving path");
        return;
    }

    FILE *file = fopen(abs_path, "r");
    char line[MAX_LINE_LENGTH];

    if (fgets(line, sizeof(line), file) != NULL) {
        printf("Headers:\n");
        char *token = strtok(line, ";");
        int col = 1;
        
        while (token != NULL) {
            printf("Column %d: %s\n", col++, token);
            token = strtok(NULL, ";");
        }
    }

    printf("\nData:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ";");
        int col = 1;
        
        while (token != NULL) {
            printf("Row %ld, Column %d: %s\n", (ftell(file) / sizeof(line)) - 1, col++, token);
            token = strtok(NULL, ";");
        }
    }
    fclose(file);
}