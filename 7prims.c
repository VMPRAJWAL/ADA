#include<stdio.h>
#include<stdlib.h>
#define INF 9999;

int prims(int **arr, int n){
    int visited[n];
    for(int i=0; i<n; i++){
        visited[i] =0;
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0) arr[i][j]=INF;
        }
    }

    int edges =0; 
    int mincost =0;
    int u=-1, v=-1;
    visited[0]=1;
    
    while(edges < n-1){
        int min=INF;
        for(int i=0; i<n; i++){
            if(visited[i]){
                for(int j=0; j<n; j++){
                    if(!visited[j] && arr[i][j] <min){
                        min=arr[i][j];
                        u=i; v=j;
                    }
                }
            }
        }
        printf("Edge %d: (%d, %d) cost: %d\n", edges, u, v, min);
        visited[v]=1;
        edges++;
        mincost += min;

    }
    return mincost;
}

void main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int mincost = prims(arr, n);
    printf("Minimum cost of the spanning tree: %d\n", mincost);

    for(int i=0; i<n; i++){
        free(arr[i]);
    }
    free(arr);
}
