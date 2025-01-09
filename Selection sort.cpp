#include<stdio.h>
int main()
{
	int n,a[10],i,j,temp,position;
	printf("Enter number of terms:");
	scanf("%d",&n);
	printf("\nGiven array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	for(i=0;i<n-1;i++)
	{
		position=i;
	
			for(j=i+1;j<n;j++)
			{
				if(a[position]>a[j])
				position=j;
			}
	if(position!=i)
	{
		temp=a[i];
		a[i]=a[position];
		a[position]=temp;
	}
	}
	printf("Sorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
