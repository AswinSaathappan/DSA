#include<stdio.h>
#include<stdlib.h>
int max(int arr[],int n);
int max(int arr[],int n)
{
    int maxi=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxi)
        {
           maxi=arr[i];
        }
    }
    return maxi;
}
void countingSort(int arr[],int n,int k)
{
    int count[k+1];
    int b[n];
    for (int i = 0; i <= k; i++)
    {
        count[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        ++count[arr[i]];
    }
    for(int i=1;i<=k;i++)
    {
        count[i]+=count[i-1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        b[--count[arr[i]]] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=b[i];
    }
}

int main()
{
    int n;
    printf("enter no.of elements:");
    scanf("%d",&n);
    int *arr=malloc(sizeof(int)*n);
    printf("enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int key=max(arr,n);
    printf("Before Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    countingSort(arr,n,key);
    printf("\nAfter Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
