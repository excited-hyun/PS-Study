#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

void bfs();
void dfs(int here);

int adj[1001][1001];
vector<bool> b_visit;
vector<bool> d_visit;
queue<int> bq;

int n, m, v;

int main(void){
    
    int a, b;
    
    scanf("%d %d %d", &n, &m, &v);

    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    b_visit = vector<bool>(1001, false);
    d_visit = vector<bool>(1001, false);
    
    dfs(v);
    printf("\n");
    
    bfs();
    printf("\n");
}

void dfs(int here){
    int there;
    d_visit[here] = true;
    printf("%d ", here);
    for(int i=1; i<=n; i++){
        if(adj[here][i] != 1)
            continue;
        
        there = i;
        
        if(!d_visit[there])
            dfs(there);
    }
}

void bfs(){
    int here, there;
    
    
    bq.push(v);
    b_visit[v] = true;
    while(!bq.empty()){
        here = bq.front();
        bq.pop();
        
        printf("%d ", here);
        for(int i=1; i<=n; i++){
            if(adj[here][i] != 1)
                continue;
            
            there = i;
            
            if(!b_visit[there]){
                bq.push(there);
                b_visit[there] = true;
            }
        }
    }
}
