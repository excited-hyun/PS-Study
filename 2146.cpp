#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int map[101][101];
int visited[101][101];

int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

queue<pair<int, int>> island;   //x, y
queue<pair<pair<int, int>, int>> check;   //x, y, cnt
void island_bfs(int n, int x, int y);
int bfs(int n, int x, int y, int is);
int is_num = 1;
int b_min = 10000;

int main(void){
    int n;
    int n_x, n_y;
    int near;
    int cnt;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    //printf("a\n");
    for(int i=0; i<n; i++){ //섬들 구분
        for(int j=0; j<n; j++){
            if(map[i][j] == 1){
                is_num++;
                island_bfs(n, i, j);
            }
        }
    }
    //printf("a\n");
    
    /*
    
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    */
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 0){
                near = 0;
                for(int k=0; k<4; k++){
                    n_x = i + X[k];
                    n_y = j + Y[k];
                    if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= n)
                        continue;
                    if(map[n_x][n_y]!=near && map[n_x][n_y]!=0){
                        near = map[n_x][n_y];
                        
                        cnt = bfs(n, i, j, near);
                        fill_n(&visited[0][0],101*101,0);
                        
                        if(cnt < b_min)
                            b_min = cnt;
                        
                        
                    }
                }
                
            }
        }
    }
    
    
    printf("%d\n", b_min);
    
    
}
void island_bfs(int n, int x, int y){
    int p_x, p_y, n_x, n_y;
    island.push(make_pair(x, y));
    map[x][y] = is_num;
    
    while(!island.empty()){
        p_x = island.front().first;
        p_y = island.front().second;
        island.pop();
        
        for(int i=0; i<4; i++){
            n_x = p_x + X[i];
            n_y = p_y + Y[i];
            if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= n)
                continue;
            if(map[n_x][n_y] == 1){
                map[n_x][n_y] = is_num;
                island.push(make_pair(n_x, n_y));
            }
        }
    }
}


int bfs(int n, int x, int y, int is){
    int p_x, p_y, n_x, n_y;
    int cnt;
    int result=10000;
    
    check.push(make_pair(make_pair(x, y), 0));
    visited[x][y] = 1;
    
    while(!check.empty()){
        p_x = check.front().first.first;
        p_y = check.front().first.second;
        cnt = check.front().second;
        check.pop();
        if(map[p_x][p_y]!=0 && map[p_x][p_y] != is){
            while(!check.empty())
                check.pop();
            result = cnt;
            break;
        }
        
        for(int i=0; i<4; i++){
            n_x = p_x + X[i];
            n_y = p_y + Y[i];
            if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= n)
                continue;
            if(map[n_x][n_y] != is && visited[n_x][n_y] == 0){
                check.push(make_pair(make_pair(n_x, n_y), cnt+1));
                visited[n_x][n_y] = 1;
            }
        }
    }
    
    return result;
}
