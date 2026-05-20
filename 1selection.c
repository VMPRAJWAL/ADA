#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minindex= i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<minindex){ minindex = j;}
        }
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int));

    clock_t start, end;
    for(int i=0; i<n; i++){
        arr[i]= rand()%100000;
    }
    printf("The Random Numbers are:\n");
    print(arr,n);

    start = clock();
    selectionSort(arr,n);
    end = clock();

    printf("Sorted numbers are: \n");
    print(arr,n);

    return 0;
}

// Time Complexity: O(n^2) in all cases