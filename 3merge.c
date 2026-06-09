#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *arr, int *temp, int lb, int mid, int ub){
    int i=lb, k=lb, j=mid+1;

    while(i<mid && j<ub){
        if(arr[i] > arr[j]) temp[k++] = arr[j++];
        else temp[k++] = arr[i++]; 
    }

    while(i<= mid) temp[k++] = arr[i++];

    while(j<= ub) temp[k++] = arr[j++];

    for(int a=0; a<ub; a++) arr[a] = temp[a];
}

void mergesort(int *arr, int *temp, int lb, int ub){
    int mid = lb + ((ub-lb)/2);
    if(lb<ub){
        mergesort(arr, temp, lb, mid);
        mergesort(arr, temp, mid+1, ub);
        merge(arr, temp, lb, mid, ub);
    }
}

void main(){
    int n; 
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int) * n);
    int *temp = (int*)malloc(sizeof(int) * n);
    
    printf("Array before Sorting: \n");
    for(int i=0; i<n; i++){
        arr[i] = rand()%100000;
        printf("%d ", arr[i]);
    }

    clock_t a,b;

    a= clock();
    mergesort(arr, temp, 0, n);
    b=clock();

    printf("\nSorted array: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("Total Time Taken: %lf \n", (double)(b-a)/CLOCKS_PER_SEC);

    free(arr);
    free(temp);
}
