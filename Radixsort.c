#include <stdio.h>

int getmax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void countsort(int a[], int n, int pos) {
    int b[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        ++count[(a[i]/pos)%10];
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        b[--count[(a[i]/pos)%10]] = a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void radixsort(int a[],int n)
{
    int max=getmax(a,n);
    for(int pos=1; max/pos>0; pos*=10)
    {
        countsort(a,n,pos);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    radixsort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
