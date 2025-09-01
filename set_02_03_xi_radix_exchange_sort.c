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