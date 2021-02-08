#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
int way[100][100];
int can[100][100];

queue<int> q;

void bfs(int s, int n);

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            scanf("%d", &way[i][j]);
    }
    for(int i=0; i<n; i++){
        bfs(i, n);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d ", can[i][j]);
        
        printf("\n");
    }
}


void bfs(int s, int n){
    int visited[100];
    int here;
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }
    q.push(s);
    
    while(!q.empty()){
        here = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(way[here][i] == 0 || visited[i] == 1)
                continue;
            q.push(i);
            
            can[s][i] = 1;
            visited[i] = 1;
        }
    }
}
