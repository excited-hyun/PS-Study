#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

char map[100][100];
int visited[250][250];

int C[4] = {1, -1, 0, 0};
int R[4] = {0, 0, 1, -1};
int cnt;

void dfs(int n, int m, int now_r, int now_c);

int main (void){
    int t;
    int n, m;
    scanf("%d", &t);
    
    for(int i=0; i<t; i++){
        cnt = 0;
        scanf("%d %d", &n, &m);
    
        for(int i=0; i<n; i++){
           
            scanf("%s", map[i]);
        }
    
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == 0 && map[i][j] == '#'){
                    dfs(n, m, i, j);
                    cnt++;
                }
            }
        }
        
        printf("%d\n", cnt);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                visited[i][j] = 0;
            }
        }
        
    }

   
    
}

void dfs(int n, int m, int now_r, int now_c)
{
    int next_r, next_c;
    
    visited[now_r][now_c] = 1;
 
    for(int i=0; i<8; i++){
        next_r = now_r + R[i];
        next_c = now_c + C[i];
        
        if(next_r <0 || next_r >=n || next_c <0 || next_c >=m)
            continue;
        
        if(visited[next_r][next_c]==1)
            continue;
        
        if(map[next_r][next_c]=='.')
            continue;
        
        dfs(n, m, next_r, next_c);
    }
}
