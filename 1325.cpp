#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> map;
int visited[10001];
int cnt;
int vi[10001];

void dfsAll(int s, int n);
void dfs(int here, int n);

int main(void){
    int n, m;
    int a,b;
    int max =0;
    scanf("%d %d", &n, &m);
    
    map.resize(n+1);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        map[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        cnt = 0;
        dfsAll(i, n);
        vi[i] = cnt;
        if(max < cnt)
            max = cnt;
    }
    
    for(int i=1; i<=n; i++){
        if(vi[i] == max)
            printf("%d ", i);
    }
    printf("\n");
    
}

void dfsAll(int s, int n){
    for(int i=1; i<=n; i++){
        visited[i] = 0;
    }
    dfs(s, n);
    
}

void dfs(int here, int n){
    int there;
    visited[here] = 1;
    cnt++;
    for(int i=0; i<map[here].size(); i++){
        there = map[here][i];
        if(visited[there] == 1)
            continue;
        dfs(there, n);
    }
    
}
