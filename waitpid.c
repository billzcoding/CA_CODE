#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    pid_t pid;
    
    pid = fork(); 

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("I am the child (PID: %d). I will exit soon.\n", getpid());
        sleep(1); // Simulate work
    } else { 
        // Parent process
        printf("I am the parent (PID: %d). Waiting for child %d.\n", getpid(), pid);
        
        // Wait specifically for the child process identified by 'pid'
        waitpid(pid, NULL, 0); 
        
        printf("Parent detected child %d has terminated.\n", pid);
    }
    
    return 0;
}