#include<stdio.h>

int max(int a, int b){ return a>b ? a : b;}

int main(){
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    int wt[n+1], p[n+1], w, i, cap;

    printf("Enter the weights: \n");
    for(i=1; i<=n; i++){
        scanf("%d", &wt[i]);
    }

    printf("Enter the profits: \n");
    for(i=1; i<=n; i++){
        scanf("%d", &p[i]);
    }
    
    printf("Enter the capacity: ");
    scanf("%d", &cap);

    int dp[n+1][cap+1]; 
    
    for(i=0; i<=n; i++){
        for(w=0; w<=cap; w++){
            if(i==0 || w==0) dp[i][w]=0;
            
            else if(wt[i] <= w){
                int a= p[i] + dp[i-1][w-wt[i]];
                int b= dp[i-1][w];
                dp[i][w] = max(a, b);
            }

            else dp[i][w] = dp[i-1][w];
        }
    }

    printf("Items Included: ");
    printf("Items\tWeight\tProfit\n");

    w=cap;
    int tp= dp[n][cap];
    for(i=n; i>0 && tp>0; i--){
        if(tp!= dp[i-1][w]){
            printf("%d\t%d\t%d\n", i, wt[i], p[i]);
            tp -= p[i];
            w -= wt[i];
        }
    }

    printf("Maximum profit: %d\n", dp[n][cap]);
    return 0;
}