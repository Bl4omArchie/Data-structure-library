#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 10  // Adjust this based on the maximum number of columns expected

void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];

    // Read the header line
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

    // Read the data lines
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

int main() {
    const char *filename = "csv/test_linked_list.csv";  // Change to your CSV filename
    read_csv(filename);
    return 0;
}