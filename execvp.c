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

    if (pid == 0) {
        printf("Child (PID: %d) is running 'date'...\n", getpid());
        
        char *cmd = "date";
        char *args[] = {"date", NULL}; 
        
        execvp(cmd, args);
        
        perror("execvp failed");
        exit(1);
    } else {
        printf("Parent (PID: %d) waiting for child %d to finish.\n", getpid(), pid);
        
        wait(NULL);
        
        printf("Parent detected child termination. Execution continues.\n");
    }
    
    return 0;
}