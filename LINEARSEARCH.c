#include<stdio.h>
int linearsearch(int arr[],int n,int key)
{
 for(int i=0; i<n; i++)
 {
   if(arr[i] == key)
   {
    return i;
   }
 }
 return -1;
}

int main()
{
    int n,key;
    printf("enter n:");
    scanf("%d",&n);
    int *arr=malloc(sizeof(int)*n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter key:");
    scanf("%d",&key);
    int k=linearsearch(arr,n,key);
    if(k==-1)
    {
        printf("The key is not found");
    }
    else
    {
      printf("The key us found at index: %d",k);
    }
    return 0;
}
