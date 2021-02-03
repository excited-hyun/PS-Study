#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int map[100][100];
int cost[100][100];

int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

priority_queue<pair<int, pair<int, int>>> pq; //cost, x, y

int main(void){
    int n, m;
    int x, y, cnt;
    int next_x, next_y, next_cnt;
    
    scanf("%d %d", &m, &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
            cost[i][j] = -1;
        }
    }
    cost[0][0] = 0;
    pq.push(make_pair(0,make_pair(0, 0)));
    
    while(!pq.empty()){
        cnt = -pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();
        
        if(cost[x][y] < cnt)
            continue;
        
        for(int i=0; i<4; i++){
            next_x = x + X[i];
            next_y = y + Y[i];
            next_cnt = cnt + map[next_x][next_y];
            
            if(next_x < 0 || next_x >= n || next_y<0 || next_y >= m)
                continue;
            
            if(cost[next_x][next_y] == -1){
                cost[next_x][next_y] = next_cnt;
                pq.push(make_pair(-next_cnt,make_pair(next_x, next_y)));
            }
            else if(cost[next_x][next_y] > next_cnt){
                cost[next_x][next_y] = next_cnt;
                pq.push(make_pair(-next_cnt,make_pair(next_x, next_y)));
            }
        }
    }
    printf("%d\n", cost[n-1][m-1]);
}
