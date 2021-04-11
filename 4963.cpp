#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[51][51];
int visited[51][51];

int C[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int R[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int cnt;

void dfs(int n, int m, int now_r, int now_c);

int main (void){
    int h, w;
    
    while(1){
        scanf("%d %d", &w, &h);
        if(h==0 && w==0)
            break;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d", &map[i][j]);
            }
        }
        
        cnt = 0;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(visited[i][j] ==0 && map[i][j] == 1){
                    dfs(h, w, i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                visited[i][j] = 0;
            }
        }

    }
}

void dfs(int n, int m, int now_r, int now_c){
    int next_r, next_c;
    
    visited[now_r][now_c] = 1;
    
    for(int i=0; i<8; i++){
        next_r = now_r + R[i];
        next_c = now_c + C[i];
        if(next_r <0 || next_r >=n || next_c <0 || next_c >= m)
            continue;
        if(map[next_r][next_c]==0)
            continue;
        if(visited[next_r][next_c] == 1)
            continue;
        dfs(n, m, next_r, next_c);
    }
}
