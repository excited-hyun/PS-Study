#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};
queue<pair<int, int>> check;
int map[101][101];  //외부 = -1, 내부 = 0, 치즈 = 1
int visited[101][101];

void check_out(int n, int m);   //외부공간 확인하는 함수

int main (void){
    int n, m;
    int near_x, near_y;
    int cheese_cnt= 0;
    int day = 0;
    int cnt = 0;

    
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1)
                cheese_cnt++;
        }
    }

    while(cheese_cnt !=0){
        //printf("%d\n", cheese_cnt);
        day++;
        check_out(n, m);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(map[i][j] != 1)
                    continue;
                
                cnt = 0;
                for(int k=0; k<4; k++){
                    near_x = i + X[k];
                    near_y = j + Y[k];
                    if(near_x < 0 || near_x >= n || near_y <0 || near_y >=m)
                        continue;
                    if(map[near_x][near_y] == -1)
                        cnt++;
                    
                }
                //printf("%d\n", cnt);
                if(cnt >=2){
                    map[i][j] = 0;
                    cheese_cnt--;
                }
                
                if(cheese_cnt == 0){
                    printf("%d\n", day);
                    return 0;
                }
            }
        }
    }
}

void check_out(int n, int m){

    int found = 0;
    int s_x, s_y;
    int n_x, n_y;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = 0;
        }
    }
    
    //각각의 모서리 확인
    for(int i=0; i<n; i++){
        if(map[i][0] == 0 || map[i][0] == -1){
            found = 1;
            s_x = i;
            s_y = 0;
            break;
        }
    }
    if(found == 0){
        for(int j=0; j<m; j++){
            if(map[0][j] == 0 || map[0][j] == -1){
                found = 1;
                s_x = 0;
                s_y = j;
                break;
            }
        }
    }
    if(found == 0){
        for(int j=0; j<m; j++){
            if(map[n-1][j] == 0 || map[n-1][j] == -1){
                found = 1;
                s_x = n-1;
                s_y = j;
                break;
            }
        }
    }
    if(found == 0){
        for(int i=0; i<n; i++){
            if(map[i][m-1] == 0 || map[i][m-1] == -1){
                found = 1;
                s_x = i;
                s_y = m-1;
                break;
            }
        }
    }
    check.push(make_pair(s_x, s_y));
    visited[s_x][s_y] = 1;
    map[s_x][s_y] = -1;
    
    while(!check.empty()){
        s_x = check.front().first;
        s_y = check.front().second;
        check.pop();
        for(int i=0; i<4; i++){
            n_x = s_x + X[i];
            n_y = s_y + Y[i];
            if(n_x < 0 || n_x >= n || n_y <0 || n_y >=m)
                continue;
            if(visited[n_x][n_y] || map[n_x][n_y] == 1)
                continue;
            check.push(make_pair(n_x, n_y));
            visited[n_x][n_y] = 1;
            map[n_x][n_y] = -1;
        }
    }
    
}
