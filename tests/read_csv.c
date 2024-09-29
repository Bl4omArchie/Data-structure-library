#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2048

void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    
    // Lire l'entête (première ligne du CSV)
    if (fgets(line, sizeof(line), file)) {
        printf("%s", line); // Affiche l'en-tête
    }

    /* Lire chaque ligne de données
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    */

    fclose(file);
}

int main() {
    read_csv("dataset_B_05_2020.csv");
    return 0;
}