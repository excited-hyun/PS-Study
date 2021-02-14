#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char map[50][50];
int visited[50][50];
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};
int s_x, s_y;
int cnt;

void dfs(int x, int y, int n, int m);

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
         scanf("%s", map[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            cnt = 0;
            s_x = i;
            s_y = j;
            dfs(i, j, n, m);
        }
    }
    printf("No\n");
}

void dfs(int x, int y, int n, int m){
    int next_x, next_y;
    
    visited[x][y] = 1;
    
    cnt++;
    
    for(int i=0; i<4 ;i++){
        next_x = x+X[i];
        next_y = y+Y[i];
        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >=m)
            continue;
        if(map[next_x][next_y] != map[x][y])
            continue;
        if(visited[next_x][next_y] == 1  && next_x==s_x && next_y==s_y && cnt > 3){
            printf("Yes\n");
            exit(0);
        }
        if(visited[next_x][next_y] == 1)
            continue;
        
        dfs(next_x, next_y, n,m);
    }
    visited[x][y] = 0;
    cnt --;
}
