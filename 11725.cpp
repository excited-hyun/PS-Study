#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int visited[100001];
int t_parent[100001];
vector<vector<int>> map;

void dfs(int n, int now);

int main(void){
    int n;
    int a, b;
    
    scanf("%d", &n);
    map.resize(n+1);
    
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &a, &b);
        map[b].push_back(a);
        map[a].push_back(b);
    }
    
    dfs(n, 1);
    
    for(int i=2; i<=n; i++){
        printf("%d\n", t_parent[i]);
    }
}

void dfs(int n, int now){
    int next;
    
    visited[now] = 1;
    
    for(int i=0; i<map[now].size(); i++){
        next = map[now][i];
        if(visited[next] == 1)
            continue;
        
        t_parent[next] = now;
        dfs(n, next);
    }
}
