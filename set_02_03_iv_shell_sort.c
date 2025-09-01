// Shell Sort using C ****************************************************************

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int arr[], int n){
    for(int gap = n/2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main(){
    int arr[100], number;

    printf("\n enter total number of elements : ");
    scanf("%d", &number);
    printf("\n enter the array elements : ");

    for(int i = 0; i < number; i++){
        scanf("%d", &arr[i]);
    }

    shellSort(arr, number);

    printf("\n sorted array is : ");
    for(int i = 0; i < number; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}