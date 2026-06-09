#include<stdio.h>
#include<stdlib.h>
#define INF 9999

int kruskal(int **arr, int n){
    // Implementation of Kruskal's algorithm

    int parent[n];
    for(int i=0;i<n;i++) parent[i]=0;
    int find(int i){
        while(parent[i]) i=parent[i];
        return i;
    }
    int uni(int i, int j){
        parent[i]=j;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] ==0) arr[i][j] = INF;
        }
    }
    int edges=0; int mincost=0;

    while(edges < n-1){
        int min=INF;
        int u=-1, v=-1, a=-1, b=-1;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] < min){
                    min=arr[i][j];
                    a=u=i; b=v=j;
                }
            }
        }

        u=find(u);
        v=find(v);

        if(u!=v){
            uni(u,v);
            printf("Edge %d: (%d, %d) cost: %d\n", edges, a, b, min);
            mincost += min;
            edges++;
        }

        arr[a][b] = arr[b][a] = INF;
    }
    return mincost;
}
int main(){
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

    int mincost = kruskal(arr, n);
    printf("Minimum cost of the spanning tree: %d\n", mincost);

    for(int i=0; i<n; i++){
        free(arr[i]);
    }
    free(arr);
}
