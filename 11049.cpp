#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>

using namespace std;

int dp[501][501];
int mat[501][2];

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=1; i<n+1; i++){
        scanf("%d %d", &mat[i][0], &mat[i][1]);
        for(int j=1; j<n+1; j++)
            dp[i][j] = 987654321;
        dp[i][i] = 0;
    }
    
    for(int i=1; i<n+1; i++){
        dp[i][i+1] = mat[i][0]*mat[i][1]*mat[i+1][1];
    }
    
    for(int i=2; i<n; i++){
        for(int j=1; j<n-i+1; j++){
            for(int k=j; k<j+i; k++){
                dp[j][j+i] = min(dp[i][j], dp[j][k] + dp[k+1][i+1] + mat[j][0] * mat[k+1][0] *mat[j+i][1]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
}
