#include<stdio.h>

#define MAX 10
#define INF 999

int main() {

    int cost[MAX][MAX];
    int visited[MAX] = {0};

    int n;
    int edges = 0;
    int mincost = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");

    // Read adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            // Replace 0 with INF except diagonal
            if(cost[i][j] == 0) {

                cost[i][j] = INF;
            }
        }
    }

    // Start from first node
    visited[0] = 1;

    while(edges < n - 1) {

        int min = INF;
        int u = -1;
        int v = -1;

        // Find minimum edge
        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                for(int j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Print selected edge
        printf("Edge %d:(%d %d) cost:%d\n",edges + 1, u + 1, v + 1, min);
        mincost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum cost=%d", mincost);

    return 0;
}