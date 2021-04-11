#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[501][501];
int visited[501];
int cnt[501];

void dfs(int n, int now, int start);
void inverse_dfs(int n, int now, int start);

int main(){
    int n, m;
    int a, b;
    int total=0;
    
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = -1;
    }
    
    for (int i=1; i<=n;i++){
        dfs(n, i, i);
        for (int i=1; i<=n;i++){
            visited[i] = 0;
        }
        
        inverse_dfs(n, i, i);
        for (int i=1; i<=n;i++){
            visited[i] = 0;
        }
    }
    
    for(int i=1; i<=n; i++){
        if(cnt[i] == n+1){
            total++;
        }
    }
    printf("%d\n", total);
}

void dfs(int n, int now, int start){
    
    if(visited[now] == 0)
        cnt[start]++;
    visited[now] = 1;
    
    for(int i=1; i<n+1; i++){
        if(map[now][i]==1 && visited[i] == 0){
            dfs(n, i, start);
        }
    }
    
}

void inverse_dfs(int n, int now, int start){
    if(visited[now] == 0)
        cnt[start]++;
    visited[now] = 1;
    
    for(int i=1; i<n+1; i++){
        if(map[now][i]==-1 && visited[i] == 0){
            inverse_dfs(n, i, start);
        }
    }
}
