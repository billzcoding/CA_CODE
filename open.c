// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
    // if file does not have in directory
    // then file first.txt is created
    int fd = open("foo.txt", O_RDONLY | O_CREAT); 
    
    printf("fd = %d\n", fd);

    if (fd == -1)
    {
        // print which type of error have in a code
        printf("Error Number %d\n", errno);
        
        // print program detail "Success or failure"
        perror("Program");
    }
    close(fd);
    return 0;
}