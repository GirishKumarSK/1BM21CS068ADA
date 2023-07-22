#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

double measure_quick_sort_time(int arr[], int array_size) {
    clock_t start_time, end_time;
    start_time = clock();
    quick_sort(arr, 0, array_size - 1);
    end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    return time_taken;
}

int main() {

    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    int arr[n];

    //printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        arr[i]=rand();
        //scanf("%d", &arr[i]);
    }

    /*for (int i = 0; i < n; i++) {
        printf("%d ,",arr[i]);
        //scanf("%d", &arr[i]);
    }
    */

        double time_taken = measure_quick_sort_time(arr, n);
        printf("Array size: %d, Time taken: %f seconds\n", n, time_taken);

    return 0;
}
