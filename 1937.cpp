#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[501][501];
int keep[501][501];

int R[4] = {1, -1, 0, 0};
int C[4] = {0, 0, 1, -1};


int dfs(int n, int r, int c);

int main(void){
    int n;
    int max_d = 0;
    int temp;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            temp = dfs(n, i, j);
            //printf("%d ", temp);
            if(temp > max_d)
                max_d = temp;
        }
        //printf("\n");
    }
    printf("%d\n", max_d);
    
}

int dfs(int n, int r, int c){
    int next_r, next_c;
    int temp;
    
    if(keep[r][c])
        return keep[r][c];
    
    keep[r][c] = 1;

    
    
    for(int i=0; i<4; i++){
        next_r = r + R[i];
        next_c = c + C[i];
        if(next_r < 0 || next_r >=n || next_c < 0 || next_c >=n)
            continue;
        if(map[next_r][next_c] > map[r][c]){
            temp = dfs(n, next_r, next_c) + 1;
            if(keep[r][c] < temp)
                keep[r][c] = temp;
        }
    }
    
    return keep[r][c];
}
