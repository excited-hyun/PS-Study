#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue<pair<int,pair<int, int>>> q;
int map[505][505];
int visit[505][505];
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};
int p_size;
int ma;
int cnt;

void bfs(int n, int m);

int main(void){
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visit[i][j] == 1)
                continue;
            if(map[i][j] == 0)
                continue;
            visit[i][j] = 1;
            q.push(make_pair(1, make_pair(i, j)));
            bfs(n,m);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    printf("%d\n", ma);
}

void bfs(int n, int m){
    int x, y, s;
    int next_x, next_y, next_s;
    while(!q.empty()){

        s = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        q.pop();
        for(int i=0; i<4; i++){
            next_x = x + X[i];
            next_y = y+ Y[i];
            
            if(next_x < 0 || next_x >= n|| next_y<0 || next_y >=m)
                continue;
            if(visit[next_x][next_y] == 1 || map[next_x][next_y]== 0)
                continue;
            
            visit[next_x][next_y] = 1;
            s++;
            q.push(make_pair(s, make_pair(next_x, next_y)));
            
            if(ma < s)
                ma = s;
        }
    }
}
