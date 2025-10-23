#include <stdio.h>

int main() {
    FILE *fp;
    int year = 2025;
    char name[] = "Current Year";

    // Open file in write mode ("w"). Creates or overwrites the file.
    fp = fopen("output.txt", "w"); 

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // fprintf() writes formatted data to the file stream (fp)
    fprintf(fp, "%s: %d\n", name, year);

    // Close the file
    fclose(fp);
    
    printf("Data successfully written to output.txt\n");

    return 0;
}