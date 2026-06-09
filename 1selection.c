#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionsort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int minidx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minidx]){
                minidx = j;
            }
        }
        int temp = arr[i];
        arr[i]= arr[minidx];
        arr[minidx] = temp;
    }
}

void main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    selectionsort(arr, n);
    clock_t end = clock();

    printf("Sorted array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
}
