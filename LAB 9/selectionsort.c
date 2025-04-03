#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n;
   printf("Enter the no of elements:");
  scanf("%d",&n);
  int *a = malloc(sizeof(int)*n);
  for(int i=0; i<n; i++)
  {
    scanf("%d",&a[i]);
  }
  int temp;
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
            if(min!=i)
            {
                temp=a[i];
                a[i]=a[min];
                a[min]=temp;
            }

    }
    printf("Sorted array:");
  for(int i=0; i<n; i++)
  {
     printf("%d ",a[i]);
  }
}
