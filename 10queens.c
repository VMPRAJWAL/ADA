#include<stdio.h>
#include<stdlib.h>

int scount=0;

void printboard(int board[], int n){
    scount++;
    printf("\nSolution #%d:\n", scount);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i] == j){
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int issafe(int board[], int row, int col){
    for(int i=0; i<row; i++){
        if(board[i] == col || abs(board[i] -col)==abs(i-row)){
            return 0;
        }
    }
    return 1;
}

void solve(int board[], int row, int n){
    if(row == n){
        printboard(board, n);
        return;
    }

    for(int col=0; col<n; col++){
        if(issafe(board, row, col)){
            board[row] = col;
            solve(board, row+1, n);
        }
    }
}

int main(){
    int n;
    printf("Enter the number of queens (n): ");
    scanf("%d", &n);
    int board[n];
    solve(board, 0, n);
    printf("\nTotal solutions: %d\n", scount);
    return 0;
}