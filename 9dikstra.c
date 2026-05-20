#include<stdio.h>

#define INF 999

void dijkstra(int graph[100][100], int n) {

    int dist[100];
    int visited[100] = {0};

    int source = 0; // first node as source

    // Initialize distances
    for(int i = 0; i < n; i++) {
        dist[i] = graph[source][i];
    }

    visited[source] = 1;
    dist[source] = 0;

    // Main logic
    for(int count = 0; count < n - 1; count++) {
        int min = INF;
        int min_index = -1;
        // Find nearest unvisited vertex
        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                min_index = i;
            }
        }

        visited[min_index] = 1;

        // Update shortest distances
        for(int i = 0; i < n; i++) {
            if(!visited[i] &&
               graph[min_index][i] != INF &&
               dist[min_index] + graph[min_index][i] < dist[i]) {

                dist[i] = dist[min_index] + graph[min_index][i];
            }
        }
    }

    // Print result
    printf("\nShortest distances from source vertex 0:\n");

    for(int i = 0; i < n; i++) {
        printf("To vertex %d : %d\n", i, dist[i]);
    }
}

int main() {

    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[100][100];
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            // Replace 0 with INF except diagonal
            if(graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    dijkstra(graph, n);

    return 0;
}