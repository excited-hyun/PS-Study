#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int map[300][300];
int melt[300][300];
int visited[300][300];
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

void dfsAll(int n, int m);
void dfs(int n, int m, int x, int y);
int cnt;
int main(void){
    int n, m;
    int time = 0;
    int zero=0;
    
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }
    while(1){
        cnt = 0;
        dfsAll(n, m);

        if(cnt > 1)
            break;
        zero = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                melt[i][j] = map[i][j];
            }
        }
        
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(melt[i][j] == 0){
                    zero++;
                    continue;
                }
                if(melt[i-1][j] == 0)
                    map[i][j]--;
                if(melt[i][j-1] == 0)
                    map[i][j]--;
                if(melt[i+1][j] == 0)
                    map[i][j]--;
                if(melt[i][j+1] == 0)
                    map[i][j]--;
                
                if(map[i][j]<0)
                    map[i][j] = 0;
            }
        }
        time++;

        if(zero == (n-2)*(m-2)){
            time = 0;
            break;
        }
    }
    printf("%d\n", time);
}

void dfsAll(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = 0;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] != 0 && visited[i][j] == 0){
                dfs(n, m, i, j);

                cnt++;
            }
        }
    }
}
void dfs(int n, int m, int x, int y){
    int there_x, there_y;
    
    visited[x][y] = 1;
    for(int i=0; i<4; i++){
        there_x = x+X[i];
        there_y = y+Y[i];
        if(there_x < 1 || there_x >= n-1 || there_y < 1 || there_y >=m-1)
            continue;
        if(visited[there_x][there_y] == 1 || map[there_x][there_y] == 0)
            continue;
        dfs(n, m, there_x, there_y);
    }
}
