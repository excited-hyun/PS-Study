#include <iostream>
#include <cstdio>
#include <vector>

char map[20][20];
int visited[20][20];

int alpha[26];
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

void dfs(int x, int y, int r, int c);

int cnt, max;

int main(void){
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++){
        scanf("%s", map[i]);
    }
    
    dfs(0, 0, r, c);
    printf("%d\n", max);
}

void dfs(int x, int y, int r, int c){
    int there_x;
    int there_y;
    int ap;
    
    visited[x][y] = 1;
    ap = map[x][y] - 'A';
    alpha[ap] = 1;
    cnt++;
    if(max < cnt)
        max = cnt;
    
    for(int i=0; i<4; i++){
        there_x = x + X[i];
        there_y = y + Y[i];
        if(there_x < 0 || there_x >= r || there_y < 0 || there_y >= c)
            continue;
        ap = map[there_x][there_y] - 'A';
        
        if(visited[there_x][there_y] == 1 || alpha[ap] == 1)
            continue;
        
        dfs(there_x, there_y, r, c);
        
    }
    ap = map[x][y] - 'A';
    alpha[ap] = 0;
    visited[x][y] = 0;
    cnt--;
}
