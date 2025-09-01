// Selection Sort Using C ************************************************************

#include <stdio.h>

int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        if (min != i) {
            int t = arr[i];
            arr[i] = arr[min];    
            arr[min] = t;
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}


// Insertion Sort using C ***********************************************************

#include <stdio.h>

int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j], j--;
        arr[j + 1] = key;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}


// Bubble Sort using C *************************************************************

#include <stdio.h>

int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = n - 1; i > 0; i--) {
        int swapped = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}


// Merge Sort using C *************************************************************

#include<stdio.h> 
#include<stdlib.h>

void mergeArray(int arr[] , int l , int mid , int r){
    int temp[r - l + 1] ;
    int a = 0 ;
    int i = l ;
    int j = mid + 1 ;
    
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            temp[a++] = arr[i++] ;
        }else{
            temp[a++] = arr[j++] ;
        }
    }

    while(i <= mid){
        temp[a++] = arr[i++];
    }
    while(j <= r){
        temp[a++] = arr[j++];
    }

    for(int i = l ; i <= r ; i++){
         arr[i] = temp[i - l];
    }
}

void mergeSort(int arr[] , int l , int r){
    if(l >= r) return ;
    int mid = l + ( r - l) / 2;
    mergeSort(arr , l , mid);
    mergeSort(arr , mid + 1 , r);
    mergeArray(arr , l , mid , r);
}

int main(){
    int arr[100] , number ;

    printf(" \n enter total number of elements : ");
    scanf("%d" , &number);
    printf("\n enter the array elements : ");

    for(int i = 0 ; i < number ; i++){
        scanf("%d" , &arr[i]);
    }
    
    int l = 0;
    int r = number - 1;
    mergeSort(arr, l , r);

    printf("\n sorted array is : ");

    for(int i = 0 ; i < number ; i ++){
        printf("%d ",arr[i]);
    }

    return 0;
}


// Quick Sort using C ****************************************************************

#include<stdio.h> 
#include<stdlib.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pivot(int arr[] , int l , int r){
   int low = arr[l] ;
   int start = l;
   int end = r;
   
   while(start <= end){
       while(arr[start] <= low  && start <= end){
            start++;
       }
       while(arr[end] > low && start <= end){
            end--;
       }
       if(start < end){
            swap(&arr[start] , &arr[end]);
       }
   }

   if(start > end){
    swap(&arr[l] , &arr[end]);
   }

   return end;
}

void quickSort(int arr[] , int l , int r){
    if(l >= r) return ;
    int pivotPoint = pivot(arr, l , r);
    quickSort(arr , l , pivotPoint - 1);
    quickSort(arr, pivotPoint + 1 , r);
}

int main(){
    int arr[100] , number;

    printf(" \n enter total number of elements : ");
    scanf("%d" , &number);
    printf("\n enter the array elements : ");

    for(int i = 0 ; i < number ; i++){
        scanf("%d" , &arr[i]);
    }

    int l = 0;
    int r = number - 1;
    quickSort(arr, l , r);

    printf("\n sorted array is : ");

    for(int i = 0 ; i < number ; i++){
        printf("%d " , arr[i]);
    }

    return 0;
}


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