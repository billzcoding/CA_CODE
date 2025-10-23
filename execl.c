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
        printf("Child (PID: %d) is running '/bin/ls -l' (using execl())...\n", getpid());
        
        // EXECL: Takes arguments as a list, ending with NULL.
        // First argument: full path. Second argument: program name (convention).
        execl("/bin/ls", "ls", "-l", NULL);
        
        perror("execl failed");
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