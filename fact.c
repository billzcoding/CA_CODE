#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int num, fact;
    int i; // Loop variable

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    // CHILD PROCESS (Calculates Factorial)
    if (pid == 0) {
        fact = 1;

        printf("Child Process (PID: %d):\n", getpid());
        printf("Enter a number (<= 12 for accurate int factorial): ");
        
        if (scanf("%d", &num) != 1 || num < 0) {
            printf("Invalid input. Exiting child.\n");
            return 1;
        }

        for (i = 1; i <= num; i++) {
            fact *= i;
        }
        
        printf("Factorial of %d is: %d\n", num, fact);
        return 0; 
    } 
    
    // PARENT PROCESS (Waits)
    else {
        printf("Parent Process (PID: %d) waiting for child %d...\n", getpid(), pid);
        
        // Wait for the child process to terminate
        wait(NULL);
        
        // Display the completion message after the child has finished
        printf("Factorial calculation completed.\n");
    }

    return 0;
}