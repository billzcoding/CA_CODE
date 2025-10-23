#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    float gpa;
    int courses;
    
    // Allocate a fixed 50 characters for the name pointer
    char *namePtr = (char*)malloc(50 * sizeof(char));

    if (namePtr == NULL) {
        return 1;
    }

    printf("Enter GPA: ");
    scanf("%f", &gpa);

    printf("Enter the number of courses enrolled: ");
    scanf("%d", &courses);
    
    // Clear buffer
    getchar(); 

    printf("Enter your name: ");
    // Read up to 49 characters safely into the allocated memory
    scanf("%49[^\n]", namePtr); 
    
    printf("\nName: %s\n", namePtr);
    printf("Your GPA is %.2f and you are enrolled in %d courses.\n", gpa, courses);
    
    free(namePtr);

    return 0;
}