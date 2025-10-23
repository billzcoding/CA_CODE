#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    // Child Process: Replaced by 'ls -l' command
    if (pid == 0) {
        printf("Child (PID: %d) is running '/bin/ls -l' (using execv())...\n", getpid());
        
        // Full path is required here (e.g., /bin/ls)
        char *path = "/bin/ls";
        // Arguments array
        char *args[] = {"ls", "-l", NULL}; 
        
        // EXECV: Replaces the child's code with the 'ls' program
        execv(path, args);
        
        perror("execv failed");
        exit(1);
    } 
    
    // Parent Process: Waits for child to finish
    else {
        printf("Parent (PID: %d) waiting for child %d to finish.\n", getpid(), pid);
        wait(NULL);
        printf("Parent detected child termination. Execution continues.\n");
    }
    
    return 0;
}