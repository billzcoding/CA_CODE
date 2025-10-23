#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *fp;
    
    // 1. Open a file in read/write mode ("w+"). 
    // This creates the file or overwrites it.
    fp = fopen("seek_test.txt", "w+");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // 2. Write some initial data to the file
    fprintf(fp, "0123456789ABCDEF");

    // 3. Move the file pointer (fseek)
    // Move 8 bytes from the start (SEEK_SET)
    fseek(fp, 8, SEEK_SET);

    // 4. Check the current position (ftell)
    // It should now be at position 8
    printf("Pointer position after fseek: %ld\n", ftell(fp));

    // 5. Write new data at the new position
    fprintf(fp, "XX");

    // 6. Move the pointer back to the start
    fseek(fp, 0, SEEK_SET);

    // 7. Read the content (max 20 chars) and print it
    char buffer[20];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("File content after writing: %s\n", buffer);
    }

    // 8. Close the file
    fclose(fp);

    return 0;
}