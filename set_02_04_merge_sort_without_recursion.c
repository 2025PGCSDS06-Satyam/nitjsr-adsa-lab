#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int l, r, state;
} Frame;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1, n2 = r - mid;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) 
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSortIterative(int arr[], int n) {
    Frame stack[MAX];
    int top = -1;

    stack[++top] = (Frame){0, n - 1, 0};

    while(top >= 0) {
        Frame *f = &stack[top];
        if(f->l >= f->r) { top--; continue; }

        int mid = f->l + (f->r - f->l) / 2;

        if(f->state == 0) {
            f->state = 1;
            stack[++top] = (Frame){f->l, mid, 0};
        } 
        else if(f->state == 1) {
            f->state = 2;
            stack[++top] = (Frame){mid + 1, f->r, 0};
        } 
        else {
            merge(arr, f->l, mid, f->r);
            top--;
        }
    }
}

int main() {
    int arr[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    mergeSortIterative(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
