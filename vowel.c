#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[21]; // Array size 21 for 20 chars + null terminator
    int count = 0;
    int i;

    printf("Enter a string (max 20 characters): ");
    
    // Safely read up to 20 characters, stopping at newline
    scanf("%20[^\n]", str); 

    for (i = 0; str[i] != '\0'; i++) {
        // Convert character to lowercase for simple comparison
        char c = tolower(str[i]); 
        
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    printf("Total vowels in the string: %d\n", count);

    return 0;
}