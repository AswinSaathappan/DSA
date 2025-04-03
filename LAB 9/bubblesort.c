#include<stdio.h>
int main()
{
    int n;
    printf("Enter no of elements:");
    scanf("%d",&n);
    int *arr = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    //Bubble sort logic
    int temp;
    for(int i=0; i<n-1; i++)
    {
       for(int j=0; j<n-1-i; j++)
       {
           if(arr[j]>arr[j+1])
           {
             temp = arr[j];
             arr[j] = arr[j+1];
             arr[j+1] = temp;
           }

       }
    }
    printf("Sorted array:");
    for(int i=0 ; i<n; i++)
    {
        printf("%d  ",arr[i]);
    }

}
