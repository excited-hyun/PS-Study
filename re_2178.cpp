#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

char map[101][101];
int visited[101][101];
queue<pair<pair<int, int>, int>> check;

int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

int main(void){
    int n, m;
    int x, y, n_x, n_y;
    int cnt;
    int result= -1;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%s", map[i]);
    }
    
    check.push(make_pair(make_pair(0, 0), 1));
    visited[0][0] = 1;
    
    while(!check.empty()){
        x = check.front().first.first;
        y = check.front().first.second;
        cnt = check.front().second;
        
        check.pop();
        if(x == n-1 && y == m-1){
            result = cnt;
            break;
        }
        for(int i=0; i<4; i++){
            n_x = x+X[i];
            n_y = y+Y[i];
            if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= m)
                continue;
            if(map[n_x][n_y] == '0' || visited[n_x][n_y] == 1)
                continue;
            check.push(make_pair(make_pair(n_x, n_y), cnt+1));
            visited[n_x][n_y] = 1;
        }
    }
    printf("%d\n", cnt);
    
}
