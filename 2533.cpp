#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> map[1000001];
int dp[1000001][2];
int visited[1000001];

void dfs(int now, int n);

int main(void){
    int n;
    int u, v;
    int min_frd;
    
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%d %d", &u, &v);
        map[u].push_back(v);
        map[v].push_back(u);
        
    }
    dfs(1, n);
    min_frd = min(dp[1][0], dp[1][1]);
    
    printf("%d\n", min_frd);
}

void dfs(int now, int n){
    int next;
    
    visited[now] = 1;
    dp[now][0] = 1;     //0일 땐 얼리 어답터O
    dp[now][1] = 0;     //1일 땐 얼리어답터 X
    for(int i=0; i<map[now].size(); i++){
        next = map[now][i];
        if(visited[next] == 1)
            continue;
        dfs(next, n);
        
        dp[now][0] += min(dp[next][0], dp[next][1]);
        dp[now][1] += dp[next][0];
    }
}
