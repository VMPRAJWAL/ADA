#include<stdio.h>
#define M 100;

int main(){
    int n;
    printf("Enter the Number of vertices/nodes: ");
    scanf("%d", &n);

    int adj[n][n];
    int indeg[n];
    int visited[n];
    for(int i=0; i<n; i++){
        indeg[i] = 0;
        visited[i] = 0;
    }
    int count=0;
    printf("Enter the Adjacency Matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==1){
                indeg[j]++;
            }
        }
    }
    printf("Topological Sequence: ");
    while(count < n){
        for(int i=0; i<n; i++){
            if(indeg[i]==0 && visited[i]==0){
                printf("%d ", i);
                visited[i] = 1;
                count++;
                for(int j=0; j<n; j++){
                    if(adj[i][j]==1){
                        indeg[j]--;
                    }
                }
            }

        }

    }
    printf("\n");
    return 0;
}

//Time Complexity: O(n^2) in all cases