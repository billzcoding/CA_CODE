#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Simple function to count stats from a buffer
void count_stats(char *buffer, ssize_t size, int *lines, int *words, int *chars) {
    int i;
    int in_word = 0;
    
    for (i = 0; i < size; i++) {
        (*chars)++;
        
        if (buffer[i] == '\n') {
            (*lines)++;
            in_word = 0;
        } else if (buffer[i] == ' ' || buffer[i] == '\t') {
            in_word = 0;
        } else {
            // Found a character, check if a new word started
            if (in_word == 0) {
                (*words)++;
                in_word = 1;
            }
        }
    }
}

int main() {
    char filename[50];
    char buffer[1024];
    int lines = 0, words = 0, chars = 0;
    int fd;
    ssize_t bytes_read;
    
    printf("Enter the filename for statistics: ");
    scanf("%49s", filename);
    
    // --- System Call Logic (Read) ---
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Process the file buffer by buffer
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        count_stats(buffer, bytes_read, &lines, &words, &chars);
    }
    close(fd);
    
    // --- Output Results using fprintf() ---
    printf("\n--- File Statistics ---\n");
    fprintf(stdout, "Characters: %d\n", chars);
    fprintf(stdout, "Words: %d\n", words);
    fprintf(stdout, "Lines: %d\n", lines);
    
    return 0;
}