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