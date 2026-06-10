#include<stdio.h>

#define INF 9999

int* dijkstra(int **graph, int n, int src){
    int dist[n], visited[n];
    for(int i=0; i<n; i++){
        visited[i]=0;

        if(i!=src && graph[src][i]!=0) dist[i] = graph[src][i];
        else if(i==src) {dist[i] = 0; visited[i]=1;}
        else dist[i] = INF;
    }

    for(int count=0; count<n-1; count++){

        int min=INF, minidx=-1;

        for(int i=0; i<n; i++){
            if(!visited[i] && dist[i]<min){
                min=dist[i];
                minidx=i;
            }
        }

        visited[minidx]=1;
        for(int i=0; i<n; i++){
            if(!visited[i] && graph[minidx][i]!=INF && dist[minidx]!=INF && dist[minidx] + graph[minidx][i] < dist[i]){
                dist[i] = dist[minidx] + graph[minidx][i];
            }
        }
    }

    return dist;
}

void main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **graph = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        graph[i] = (int*)malloc(n*sizeof(int));
        for(int j=0; j<n; j++){
            printf("Enter the weight of edge from vertex %d to vertex %d (0 if no edge): ", i, j);
            scanf("%d", &graph[i][j]);
            if(graph[i][j]==0) graph[i][j]=INF;
        }
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    int *dist = dijkstra(graph, n, src);
    printf("Shortest distances from source vertex %d:\n", src);
    for(int i=0; i<n; i++){
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}
//Time Complexity: O(n^2) in all cases
