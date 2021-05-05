#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int dp[1001];
int b_dp[1001];
int num[1001];

int main(void){
    int n;
    int max = 0;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num[i]);
        dp[i] = 1;
        b_dp[i] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j= i-1; j>=0; j--){
            if(num[i] > num[j] && dp[j]+1 > dp[i]){
                dp[i] = dp[j] + 1;
                
            }
        }
    }
    for(int i=n-2; i>=0; i--){
        for(int j= i+1; j<n; j++){
            if(num[i] > num[j] && b_dp[j]+1 > b_dp[i]){
                b_dp[i] = b_dp[j]+1;
                
            }
        }
    }
    for(int i=0; i<n; i++){
        if(max < dp[i] + b_dp[i] -1){
            max = dp[i] + b_dp[i] -1;
            //printf("%d %d %d\n", i, dp[i], b_dp[i]);
        }
    }
    printf("%d\n", max);
}
