#include <stdio.h>

int main() {
    FILE *fp;
    int year;
    char name[20]; // Buffer to store the read string

    // Open file in read mode ("r")
    fp = fopen("output.txt", "r");

    if (fp == NULL) {
        printf("Error: output.txt not found or cannot be opened!\n");
        return 1;
    }

    // fscanf() reads formatted data from the file stream (fp)
    // It reads a string into 'name' and an integer into 'year'.
    fscanf(fp, "%s: %d", name, &year);

    // Print the data that was read
    printf("Data read from file: %s %d\n", name, year);

    // Close the file
    fclose(fp);

    return 0;
}