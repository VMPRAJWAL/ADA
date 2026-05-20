#include<stdio.h>

#define MAX 10
#define INF 999

int parent[MAX];

// Find parent
int find(int i) {
    while(parent[i]) {
        i = parent[i];
    }
    return i;
}

// Union of two vertices
void uni(int i, int j) {
    parent[j] = i;
}

int main() {
    int cost[MAX][MAX];
    int n;

    int mincost = 0;
    int edges = 1;

    printf("Enter the no. of vertices\n");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix\n");

    // Read matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            // Replace 0 with INF
            if(cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");

    while(edges < n) {
        int min = INF;
        int a = -1;
        int b = -1;
        int u = -1;
        int v = -1;

        // Find minimum edge
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find parents
        u = find(u);
        v = find(v);

        // If no cycle
        if(u != v) {
            printf("%d edge (%d,%d) =%d\n",
                   edges++, a + 1, b + 1, min);
            mincost += min;
            uni(u, v);
        }

        // Remove edge
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d", mincost);

    return 0;
}