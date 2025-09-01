#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n) {
    int i, j, k = 0, min = arr[0], max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int bucketCount = n; 
    int range = max - min + 1;
    int bucketRange = (range + bucketCount - 1) / bucketCount;

    int *buckets[bucketCount];
    int bucketSizes[bucketCount];

    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucketSizes[i] = 0;
    }
    for (i = 0; i < n; i++) {
        int bi = (arr[i] - min) / bucketRange;
        if (bi >= bucketCount) bi = bucketCount - 1;
        buckets[bi][bucketSizes[bi]++] = arr[i];
    }
    for (i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0)
            insertionSort(buckets[i], bucketSizes[i]);
    }
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < bucketSizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}