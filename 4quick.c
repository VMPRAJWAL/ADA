#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub){
    int pivot = arr[ub];
    int i=lb;

    while(i<ub){
        while(arr[i] < pivot) i++;
        while(arr[ub] > pivot) ub--;

        if(i<ub) swap(&arr[i], &arr[ub]);
    }
    swap(&arr[i], &arr[ub]);
    return i;
}

void quicksort(int arr[], int lb, int ub){
    if(lb<ub){
        int pivot = partition(arr, lb,  ub);
        quicksort(arr, lb, pivot-1);
        quicksort(arr, pivot+1, ub);
    }
}

int main(){
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);

    clock_t start, end;
    for(int i=0; i<n; i++){
        arr[i]= rand()%100000;
    }
    printf("The Random Numbers are:\n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    start = clock();
    quicksort(arr, 0, n-1);
    end = clock();

    printf("Sorted numbers are: \n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("Time taken: %lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}