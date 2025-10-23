#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char filename[50];
    char buffer[1024];
    int fd;
    ssize_t bytes_read;
    FILE *fp;

    printf("Enter the filename to read: ");
    scanf("%49s", filename);

    printf("\n--- Output using System Call (read()) ---\n");
    
    // 1. System Call Method
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file with system call");
        return 1;
    }

    // Read content and write it directly to standard output (file descriptor 1)
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes_read); 
    }
    close(fd);

    printf("\n\n--- Output using Standard I/O (fprintf/fscanf) ---\n");
    
    // 2. Standard I/O Method
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file with standard I/O");
        return 1;
    }

    // Read and print line by line
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        fprintf(stdout, "%s", buffer); // fprintf to stdout is equivalent to printf
    }
    fclose(fp);
    
    printf("\n");
    return 0;
}