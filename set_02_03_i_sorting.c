// Selection Sort Using C ************************************************************

#include<stdio.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[100] , number ;
    printf(" \n enter total number of elements : ");
    scanf("%d" , &number);
    printf("\n enter the array elements : ");
    for(int i = 0 ; i < number ; i++){
        scanf("%d" , &arr[i]);
    }

    for(int i = 0 ; i < number - 1 ; i++){
        int min = i;
        for(int j = i ; j < number ; j++){
            if(arr[j] < arr[min]){
                swap(&arr[j] , &arr[min]);
            }
        }
    }

    printf("\n sorted array is : ");

    for(int i = 0 ; i < number ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// Insertion Sort using C ***********************************************************

#include<stdio.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[100] , number ;

    printf(" \n enter total number of elements : ");
    scanf("%d" , &number);
    printf("\n enter the array elements : ");
    for(int i = 0 ; i < number ; i++){
        scanf("%d" , &arr[i]);
    }
    
    for(int i = 0 ; i < number ; i++){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
              swap(&arr[j-1],&arr[j]);
              j--;
        }
    }

    printf("\n sorted array is : ");

    for(int i = 0 ; i < number ; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

// Bubble Sort using C *************************************************************

#include<stdio.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[100] , number ;

    printf(" \n enter total number of elements : ");
    scanf("%d" , &number);
    printf("\n enter the array elements : ");
    for(int i = 0 ; i < number ; i++){
        scanf("%d" , &arr[i]);
    }

    for(int i = number - 1 ; i >= 1 ; i--){
        int flag = 1;
        for(int j = 0 ; j <= i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j] , &arr[j+1]);
                flag = 0;
            }
        }

        if(flag == 1) break;
    }

    printf("\n sorted array is : ");

    for(int i = 0 ; i < number ; i++){
        printf("%d ",arr[i]);
    }

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

// Heap Sort using C ****************************************************************

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;      
    int left = 2*i + 1;     
    int right = 2*i + 2;    

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n-1; i > 0; i--){
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0);    
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

    heapSort(arr, number);

    printf("\n sorted array is : ");
    for(int i = 0; i < number; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
