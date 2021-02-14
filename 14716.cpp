#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int X[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int Y[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int map[250][250];
int visited[250][250];
int cnt;

void dfs(int x, int y, int m, int n);

int main(void){
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0 ;i<m; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 1 || map[i][j] == 0)
                continue;
            dfs(i, j, m, n);
            cnt++;
        }
    }
    printf("%d\n", cnt);
}

void dfs(int x, int y, int m, int n){
    int next_x, next_y;
    
    visited[x][y] = 1;
    for(int i=0; i<8; i++){
        next_x = x+X[i];
        next_y = y+Y[i];
        if(next_x < 0 || next_x >=m || next_y < 0 || next_y >= n)
            continue;
        if(visited[next_x][next_y] == 1 || map[next_x][next_y] == 0)
            continue;
        dfs(next_x, next_y, m, n);
    }
}
