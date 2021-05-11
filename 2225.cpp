#include <iostream>
#include <cstdio>

int dp[201][201];

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int j=1; j<k+1; j++){
        dp[0][j] = 1;
    }
    for(int i=1; i<n+1; i++){
        dp[i][1] = 1;
    }
    
    for(int i=1; i<n+1; i++){
        for(int j=2; j<k+1; j++){
            for(int k=0; k<i+1; k++){
                dp[i][j] = (dp[i][j] + dp[i-k][j-1]) %  1000000000;
            }
        }
    }
    printf("%d\n", dp[n][k]% 1000000000);
}
