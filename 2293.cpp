#include <iostream>
#include <cstdio>

int coin[101];
int dp[10001];

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &coin[i]);
    }
    
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < k+1; j++) {
            if (j >= coin[i]) {
                dp[j] += dp[j-coin[i]];
            }
        }
    }
    printf("%d\n", dp[k]);

}
