#include "util.h"


#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 10


void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];

    if (fgets(line, sizeof(line), file) != NULL) {
        // Print the header
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