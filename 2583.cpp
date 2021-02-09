#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int map[100][100];
int visited[100][100];
int cnt;
int space;

int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};
priority_queue<int> pq;

void dfsAll(int m, int n);
void dfs(int m, int n, int here_x, int here_y);

int main(void){
    int m, n, k;
    int x1, y1, x2, y2;
    scanf("%d %d %d", &m, &n, &k);
    
    for(int i=0; i<k; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int j=x1; j<x2; j++){
            for(int l=y1; l<y2; l++){
                map[j][l] = 1;
            }
        }
    }
    
    dfsAll(m, n);
    
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++){
        space = -pq.top();
        pq.pop();
        printf("%d ", space);
    }
    printf("\n");
}

void dfsAll(int m, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0 && visited[i][j] == 0){
                space = 0;
                dfs(m,n,i,j);
                pq.push(-space);
                cnt++;
            }
        }
    }
}
void dfs(int m, int n, int here_x, int here_y){
    int there_x, there_y;
    
    visited[here_x][here_y] = 1;
    space++;
    for(int i=0; i<4; i++){
        there_x = here_x + X[i];
        there_y = here_y + Y[i];
        if(there_x<0 || there_x >=n || there_y <0 || there_y >=m)
            continue;
        if(visited[there_x][there_y] == 1 || map[there_x][there_y] == 1)
            continue;
        dfs(m, n, there_x, there_y);
    }
}
