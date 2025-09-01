// Heap Sort using C ****************************************************************

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


// Radix Sort using C ****************************************************************

#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    for (int exp = 1, max = getMax(arr, n); max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    radixSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


// Counting Sort using C ****************************************************************

#include <stdio.h>

void countingSort(int arr[], int n) {
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int count[range];
    int output[n];

    for (int i = 0; i < range; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


// Bucket Sort using C ****************************************************************

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


// radix exchange Sort using C ****************************************************************

#include <stdio.h>

int getMaxBit(int arr[], int n) {
    int max = arr[0], bit = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    while (max > 0) {
        max >>= 1;
        bit++;
    }
    return bit - 1; 
}

void radixExchangeSort(int arr[], int left, int right, int bit) {
    if (left >= right || bit < 0) return;

    int i = left, j = right;
    while (i <= j) {
        while (i <= j && ((arr[i] >> bit) & 1) == 0) i++;
        while (i <= j && ((arr[j] >> bit) & 1) == 1) j--;
        if (i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++, j--;
        }
    }

    radixExchangeSort(arr, left, j, bit - 1);
    radixExchangeSort(arr, i, right, bit - 1);
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxBit = getMaxBit(arr, n);
    radixExchangeSort(arr, 0, n - 1, maxBit);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


// address calculation Sort using C ****************************************************************

#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void addressCalculationSort(int arr[], int n) {
    int max = getMax(arr, n);

    int *table = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++) 
        table[i] = -1;
    for (int i = 0; i < n; i++) {
        int pos = arr[i];
        while (table[pos] != -1)
            pos = (pos + 1) % (max + 1);
        table[pos] = arr[i];
    }
    int k = 0;
    for (int i = 0; i <= max; i++)
        if (table[i] != -1)
            arr[k++] = table[i];

    free(table);
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    addressCalculationSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}