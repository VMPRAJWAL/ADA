#include<stdio.h>

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n], path[n][n];
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
            path[i][j] = adj[i][j];
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }

    printf("The transitive closure matrix is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
    return 0;
}