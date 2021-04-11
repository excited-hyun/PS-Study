#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int map[101][101];
int visited[101][101];
int R[4] = {1, -1, 0, 0};
int C[4] = {0, 0, 1, -1};

int max_size;
int new_size;

void dfs(int n, int m, int r, int c);

int main(void){
    int n, m, k;
    int r, c;

    
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<k; i++){
        scanf("%d %d", &r, &c);
        map[r][c] = 1;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(map[i][j] ==1 && visited[i][j] == 0){
                new_size = 0;
                dfs(n, m, i, j);
                if(new_size > max_size){
                    max_size = new_size;
                }
            }
        }
    }
    printf("%d\n", max_size);
}

void dfs(int n, int m, int r, int c){
    int next_r, next_c;
    visited[r][c] = 1;
    new_size ++;
    
    for(int i=0; i<4; i++){
        next_r = r+R[i];
        next_c = c+C[i];
        
        if(next_r < 1 || next_r > n || next_c <1 ||next_c >m)
            continue;
        if(visited[next_r][next_c]==1)
            continue;
        if(map[next_r][next_c]==0)
            continue;

        dfs(n, m, next_r, next_c);
    }
}
