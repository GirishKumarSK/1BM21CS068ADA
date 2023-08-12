#include <stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void main()
{
    int arr[10001],n,i;
    clock_t st,et;
    double ts;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    if(n<10)
    {
        printf("enter the elements of the array\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
    }
    else
    {
        printf("Providing random numbers\n");
        for(i=0;i<n;i++)
        {
            arr[i] = rand();
        }
    }
    if(n<10)
    {
        printf("before sorting \n");
        print(arr,n);
    }
   
    st = clock();
    heapSort(arr, n);
    et = clock();
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    if(n<10)
    {
        printf("\nafter sorting using mergesort\n");
        print(arr,n);
    }
   
    printf("the time taken is %f",ts);
}