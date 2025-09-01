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