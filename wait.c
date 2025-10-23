#include <stdio.h>
#include <sys/types.h>  
#include <unistd.h>     
#include <sys/wait.h>   // New header required for wait()

int main() {
    pid_t pid, mypid, myppid;

    mypid = getpid();
    printf("Before fork: Process id is %d\n", mypid);

    pid = fork(); 

    if (pid < 0) {
        perror("fork() failure\n");
        return 1;
    }

    // Child process block
    if (pid == 0) {
        printf("This is child process\n");
        mypid = getpid();
        myppid = getppid(); 
        printf("Process id is %d and PPID is %d\n", mypid, myppid);
        
        // Let the child do its work (e.g., simulate a task)
        sleep(1); 
        printf("Child process completed its task.\n");
        
    } else { 
        // Parent process block
        printf("This is parent process\n");
        
        // PARENT WAITS HERE for the child to finish
        printf("Parent is waiting for child (PID %d)...\n", pid);
        wait(NULL); 
        printf("Parent received termination signal from child.\n");
        
        // Now print the parent's final details
        mypid = getpid();
        myppid = getppid();
        
        printf("Process id is %d and PPID is %d\n", mypid, myppid);
        printf("Newly created process id or child pid is %d\n", pid);
    }
    
    return 0;
}