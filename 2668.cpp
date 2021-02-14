#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int map[101];
int visited[101];
int team[101];
int cnt;
priority_queue<int> pq;

void dfs(int here, int n);

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &map[i]);
    }
    
    for(int i=1; i<=n; i++){
        if(visited[i] != 0)
            continue;
        dfs(i, n);
    }
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++){
        printf("%d\n", -pq.top());
        pq.pop();
    }
}

void dfs(int here, int n){
    int next;
    if(visited[here] == -1 || team[here] == 1)
        return;
    
    if(visited[here] == 0){
        visited[here] = 1;
    }
    else if(visited[here] == 1){
        team[here] = 1;
        cnt++;
        pq.push(-here);
        
    }
    
    next = map[here];
    dfs(next, n);
    visited[here] = -1;
}
