#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file = fopen("employees.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;
    double sum = 0.0;

    // Skip the header line
    if (fgets(line, sizeof(line), file) == NULL) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    // Read each line
    while (fgets(line, sizeof(line), file)) {
        char *token;
        int column = 0;
        double salary = 0.0;

        // Split the line by commas
        token = strtok(line, ",");
        while (token != NULL) {
            if (column == 5) { // Salary column
                salary = atof(token);
            }
            token = strtok(NULL, ",");
            column++;
        }

        sum += salary;
        count++;
    }

    fclose(file);

    if (count > 0) {
        double average = sum / count;
        printf("Average Salary: %.2f\n", average);
    } else {
        printf("No data to process.\n");
    }

    return 0;
}
