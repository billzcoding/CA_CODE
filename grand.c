#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    pid_t pid1;

    printf("Grandparent (PID: %d) starting.\n", getpid());
    
    pid1 = fork(); 

    if (pid1 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid1 == 0) {
        pid_t pid2;
        
        printf("Parent (PID: %d) created by Grandparent (PPID: %d).\n", getpid(), getppid());
        
        pid2 = fork();
        
        if (pid2 < 0) {
            perror("Second fork failed");
            return 1;
        }

        if (pid2 == 0) {
            printf("Child (PID: %d) created by Parent (PPID: %d).\n", getpid(), getppid());
            sleep(1);
        } else {
            waitpid(pid2, NULL, 0); 
            printf("Parent detected Child %d termination.\n", pid2);
        }
    } else { 
        waitpid(pid1, NULL, 0); 
        printf("Grandparent detected Parent %d termination.\n", pid1);
    }
    
    printf("Process %d exiting.\n", getpid());
    return 0;
}