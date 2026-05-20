#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void merge(int arr[], int temp[], int lb, int mid, int ub){
    int i=lb, j=mid+1, k=lb;

    while(i<=mid && j<=ub){
        if(arr[i]<arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= ub)
        temp[k++] = arr[j++];

    for(i=lb; i<=ub; i++){
        arr[i]=temp[i];
    }
}

void mergesort(int arr[], int temp[], int lb, int ub){
    int mid = lb+(ub-lb)/2;
    if(lb<ub){
        mergesort(arr, temp, lb, mid);
        mergesort(arr, temp, mid+1, ub);
        merge(arr, temp, lb, mid, ub);
    }
}

int main(){
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);
    int *temp = malloc(sizeof(int)*n);

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
    mergesort(arr,temp, 0, n-1);
    end = clock();

    printf("Sorted numbers are: \n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("Time taken: %lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);

    free(arr);
    free(temp);
    return 0;
}