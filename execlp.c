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
        printf("Child (PID: %d) is running 'ls -l' (using execlp())...\n", getpid());
        
        // EXECLP: Takes arguments as a list, ending with NULL.
        // The first argument is the command, the following arguments are passed to it.
        execlp("ls", "ls", "-l", NULL);
        
        // This only runs if execlp failed
        perror("execlp failed");
        exit(1);
    } 
    
    // Parent Process: Waits for child to finish
    else {
        printf("Parent (PID: %d) waiting for child %d to finish.\n", getpid(), pid);
        
        // WAIT: Pauses the parent until the child process terminates
        wait(NULL);
        
        printf("Parent detected child termination. Execution continues.\n");
    }
    
    return 0;
}