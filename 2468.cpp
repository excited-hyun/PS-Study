#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int map[100][100];
int cnt;
int visited[100][100];
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

void dfs(int rain, int n);
void dfsAll(int rain, int n);


int main(void){
    int n;
    int r_max = 0;
    int max = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]> r_max)
                r_max = map[i][j];
        }
    }
    
    for(int i=0; i<= r_max; i++){
        cnt =0;
        dfsAll(i, n);
        if(cnt > max)
            max = cnt;
    }
    printf("%d\n", max);
}

void dfs(int x, int y, int rain, int n){
    int here_x, here_y;
    visited[x][y] = true;
    
    for(int i=0; i < 4; i++){
        here_x = x + X[i];
        here_y = y + Y[i];
        if(here_x < 0 || here_x >= n || here_y < 0 || here_y >= n)
            continue;
        
        if(visited[here_x][here_y] == true || map[here_x][here_y] <= rain)
            continue;
        
        dfs(here_x, here_y, rain, n);
    }
}

void dfsAll(int rain, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == false && map[i][j] > rain){
                cnt++;
                dfs(i, j, rain, n);
            }
        }
    }
}
