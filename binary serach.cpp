#include<stdio.h>
int main()
{
 int a[10],m,c=0,l=0,u,mid,n;
 printf("Enter the size of the array:");
 scanf("%d",&n);
 printf("Enter the elements in ascending order:");
 for(int i=0;i<n;i++)	
 {
 scanf("%d",&a[i]);
 }
 printf("Enter the elemnt to be searched:");
 scanf("%d",&m);
 u=n-1;
 while(l<=u)
 {
 	mid=(l+u)/2;
 	if(m==a[mid])
 	{
		c=1;
 		break;
	 }
	 else if(m<a[mid])
	 {
	 	u=mid-1;
	 }
	 else
	 {
	 	l=mid+1;
	 }
	 }
	 if(c==0)
	 {
	 
	printf("The number is not found");
     }
	else
	{
	printf("The element is found at position %d",mid+1);
    }
	 }


