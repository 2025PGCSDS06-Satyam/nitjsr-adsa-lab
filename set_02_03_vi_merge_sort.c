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