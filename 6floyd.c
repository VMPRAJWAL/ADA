#include<stdio.h>

#define INF 9999

int main(){
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    int graph[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) graph[i][j]=0;
            else graph[i][j]=INF;
        }
    }

    for(int i=0; i<e; i++){
        int u, v, w;
        printf("Enter edge %d (u(end vertex 1) v(end vertex 2) w(weight)): ", i+1);
        scanf("%d %d %d", &u, &v, &w);
        graph[u-1][v-1] = w;
    }

    printf("The distance matrix is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ 
            if(graph[i][j] == INF) printf("INF ");
            else printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    printf("The shortest path matrix is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j] == INF) printf("INF ");
            else printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("Shortest paths are: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                if(graph[i][j] == INF);
                else printf("Shortest path from %d to %d is %d\n", i+1, j+1, graph[i][j]);
            }
        }
    }
    return 0;

}