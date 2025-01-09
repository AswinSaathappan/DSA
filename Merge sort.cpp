#include <stdio.h>

int mergesort(int[], int, int);

int merge(int a[],int, int, int);

int mergesort(int a[], int low, int high)

{

int mid;

if (low < high)

{

mid=(low+high)/2; 

mergesort(a, low, mid); 

mergesort(a, mid+1,high);

merge(a, low,high, mid);

}

return 0;

}

int merge(int a[], int low, int high, int mid)

{


int i, j, k, c[50];

i = low;

k = low;

j = mid + 1;

while (i <= mid && j <= high)

{

if (a[i] < a[j])

{

c[k] = a[i];

k++;

i++;

}

else

{

c[k] = a[j];

k++;

j++;

}

}

while (i <= mid)

{

c[k] = a[i];

k++;

i++;

}

while (j <= high)

{

c[k] = a[j];

k++;

j++;

}

for (i = low; i <k; i++)

{

a[i] = c[i];

}

}

int main()

{

int n,a[30], i, low,high;

printf("\nEnter n:");
 
scanf("%d",&n); 

printf("\nEnter %d numbers:",n); 

for (i = 0; i < n; i++)

{

scanf("%d",&a[i]);

}

printf("\nGiven array:"); 

for (i = 0; i < n; i++)

{

printf("%d ",a[i]);

}

low=0;

high=n-1; 

 mergesort(a, low,high);

printf("\nsorted array:"); 

for (i = 0; i < n; i++)

{

printf("%d ",a[i]);

}

}
