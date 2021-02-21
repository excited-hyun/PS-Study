#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int map[500][500];
int dp[500][500];
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};
int cnt;

int dfs(int x, int y, int n, int m);

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }
    cnt = dfs(0, 0, n, m);
    printf("%d\n", cnt);
}

int dfs(int x, int y, int n, int m){
    int next_x, next_y;

    if(x==n-1 && y == m-1){
        
        return 1;
    }
    if(dp[x][y] != -1)
        return dp[x][y];
    
    dp[x][y] =0;
    for(int i=0; i<4; i++){
        next_x = x+X[i];
        next_y = y+Y[i];
        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
            continue;
        if(map[next_x][next_y] >= map[x][y])
            continue;

        dp[x][y] += dfs(next_x, next_y, n, m);
    }
    return dp[x][y];
}
