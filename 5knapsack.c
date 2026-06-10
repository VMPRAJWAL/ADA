#include<stdio.h>

int max(int a, int b){ return (a>b) ? a : b;}

void knapsack(int *wt, int *profit, int n, int cap){
    int dp[n+1][cap+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=cap; j++){
            if(i==0 || j==0) dp[i][j] = 0;

            else if(wt[i]<=j){
                int a= profit[i] + dp[i-1][j-wt[i]];
                int b= dp[i-1][j];
                dp[i][j] = max(a,b);
            }

            else dp[i][j] = dp[i-1][j];
        }
    }

    printf("Maximum profit: %d\n", dp[n][cap]);

    printf("Items included in the knapsack:\n");
    int j=cap;
    int tp= dp[n][cap];

    for(int i=n; i>0 && tp>0; i--){
        if(tp != dp[i-1][j]){
            printf("Item %d (weight: %d, profit: %d)\n", i, wt[i], profit[i]);
            tp-=profit[i];
            j-=wt[i];
        }
    }
}

void main(){
    int n, cap;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &cap);

    int wt[n+1], profit[n+1];
    printf("Enter the weights of the items:\n");
    for(int i=1; i<=n; i++){
        scanf("%d", &wt[i]);
    }

    printf("Enter the profits of the items:\n");
    for(int i=1; i<=n; i++){
        scanf("%d", &profit[i]);
    }

    knapsack(wt, profit, n, cap);
}
//Time Complexity: O(n*cap) in all cases
