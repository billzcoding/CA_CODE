#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr = NULL;
    int n = 0 ;

    printf("Enter the size of the array \n");
    scanf("%d",&n);

    ptr = (int *) calloc(n, sizeof(int));

    for(int i=0; i<n; i++)
    {
        printf("Enter the value %d of this array :\n",i);
        scanf("%d",&ptr[i]);
    }

        for(int i=0; i<n; i++)
    {
        printf("the value %d of this array is  %d \n",i, ptr[i]);
    }

    free(ptr);

}