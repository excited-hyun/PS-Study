#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

char map[1001][1001];
int visited[1001][1001][2];

int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

queue<pair<pair<int, int>, pair<int, int>>> check;   //x, y, cnt, 부숨

int main(void){
    int n, m;
    int x, y, n_x, n_y;
    int cnt;
    int destroy;
    int result= -1;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%s", map[i]);
    }
    
    check.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
    visited[0][0][0] = 1;
    
    while(!check.empty()){
        x = check.front().first.first;
        y = check.front().first.second;
        cnt = check.front().second.first;
        destroy = check.front().second.second;
        check.pop();
        //printf("%d %d\n", x, y);
        if(x == n-1 && y == m-1){
            printf("%d\n", cnt);
            return 0;
        }
        
        for(int i=0; i<4; i++){
            n_x = x+X[i];
            n_y = y+Y[i];
            if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= m)
                continue;
            
            if(map[n_x][n_y]=='1' && destroy == 0){
               // printf("%d %d\n", n_x, n_y);
                check.push(make_pair(make_pair(n_x, n_y), make_pair(cnt+1, 1)));
                visited[n_x][n_y][1] = 1;
            }
            else if(map[n_x][n_y]=='0' && visited[n_x][n_y][destroy]==0){
                check.push(make_pair(make_pair(n_x, n_y), make_pair(cnt+1, destroy)));
                visited[n_x][n_y][destroy] = 1;
            }
        }
    }
    printf("%d\n", result);
}
