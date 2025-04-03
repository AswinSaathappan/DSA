#include<stdio.h>
int binarysearch(int arr[],int low,int high,int key)
{
 if(low <= high)
 {
   int mid = (low + high)/2;
   if(arr[mid] == key)
   {
     return mid;
   }
   else if(arr[mid] < key)
   {
     return binarysearch(arr,mid+1,high,key);
   }
   else
   {
     return binarysearch(arr,low,mid-1,key);
   }
 }
 return -1;
}

void bubblesort(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {

            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
  int n;
    printf("enter n:");
    scanf("%d",&n);
    int *arr=malloc(sizeof(int)*n);
    printf("Enter sorted array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter key:");
    scanf("%d",&key);

    int isSorted = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = 0; // Array is not sorted
            break;
        }
    }

    if (!isSorted) {
        printf("The array is not sorted. Sorting array using bubble sort...\n");
        bubblesort(arr, n);
    }

    int k = binarysearch(arr,0,n-1,key);
    if(k == -1)
    {
      printf("The key is not found!");
    }
    else
    {
    printf("The key is found at index : %d",k);
    }
}
