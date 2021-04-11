#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[101][101];
int visited[101];
int cnt=-1;
void dfs(int n, int now);

int main (void){
    int n;
    int con;
    int a, b;
    
    scanf("%d", &n);
    scanf("%d", &con);
    for(int i=0; i<con; i++){
        scanf("%d %d", &a, &b);
        map[a][b] =1;
        map[b][a]=1;
        
    }
    dfs(n, 1);
    
    printf("%d\n", cnt);
}

void dfs(int n, int now){
    visited[now] = 1;
    cnt++;
    for(int i=1; i<n+1; i++){
        if(visited[i]==1)
            continue;
        if(map[now][i]==0)
            continue;
        dfs(n, i);
    }
}
