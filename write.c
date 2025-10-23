// C program to illustrate
// write system Call
#include<stdio.h>
#include<fcntl.h>
// Note: Additional required headers for functional code:
// #include<string.h>  (for strlen)
// #include<stdlib.h>  (for exit)
// #include<unistd.h>  (for write, open, close)

int main()
{
    int sz;
    
    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC);
    
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }
    
    // This line assumes string.h is included for strlen()
    sz = write(fd, "hello geeks\n", strlen("hello geeks\n"));
    
    printf("Size of the data written in file is: %d\n", sz);
    
    close(fd);
    
    return 0;
}