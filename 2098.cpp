#include <iostream>
#include <cstdio>
#include <limits.h>
#include <vector>

using namespace std;

int map[16][16];
int dp[16][1<<16];

int dfs(int n, int now, int visit){
    int n_visit;
    
    if(visit == (1<<n) -1){
        if (map[now][0] == 0)
            return 987654321;

        return map[now][0];
    }

    if(dp[now][visit]!=0)
        return dp[now][visit];
    
    int m = INT_MAX - 16000001;
    for(int i=0; i<n; i++){
        if(map[now][i]!= 0 && ((visit&(1 << i)) == 0)){
            n_visit = visit|(1<<i);
            
            m = min(m ,dfs(n, i, n_visit) + map[now][i]);
        }
    }
        
    dp[now][visit] = m;
    
    return dp[now][visit];
}

int main (void){
    int n;
    int result;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    result = dfs(n, 0, 1);
    printf("%d\n", result);
}
