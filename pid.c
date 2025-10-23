#include <stdio.h>
#include <sys/types.h>  // Essential for pid_t
#include <unistd.h>     // Essential for fork(), getpid(), getppid(), and sleep()

int main() {
    pid_t pid, mypid, myppid;

    mypid = getpid();
    printf("Before fork: Process id is %d\n", mypid);

    pid = fork();  // Error on line 11 in your log

    if (pid < 0) {
        perror("fork() failure\n");
        return 1;
    }

    // Child process block
    if (pid == 0) {
        printf("This is child process\n");
        mypid = getpid();
        myppid = getppid(); // Error on line 22 in your log
        printf("Process id is %d and PPID is %d\n", mypid, myppid);
    } else { // Parent process block
        sleep(2);
        printf("This is parent process\n");
        mypid = getpid();
        myppid = getppid();
        
        printf("Process id is %d and PPID is %d\n", mypid, myppid);
        printf("Newly created process id or child pid is %d\n", pid);
    }
    
    return 0;
}