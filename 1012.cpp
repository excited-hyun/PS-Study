#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int map[50][50];
int visit[50][50];


int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

int main(void){
    int test;
    int m, n, k;
    int x, y;
    int new_x, new_y;
    int cnt;
    
    queue<pair<int, int>> q;
    
    scanf("%d", &test);
    
    for(int i=0; i<test; i++){
        scanf("%d %d %d", &m, &n, &k);
        
        for(int j=0; j<m; j++){
            for(int l=0; l< n; l++){
                visit[j][l] = 0;
                map[j][l] = 0;
            }
        }
        
        for(int j=0; j<k; j++){
            scanf("%d %d", &x, &y);
            map[x][y] = 1;
        }
        cnt = 0;
        
        
        for(int j=0; j<m; j++){
            for(int l=0; l< n; l++){
                if(map[j][l] == 0 || visit[j][l] == 1)
                    continue;
                visit[j][l] = 1;

                q.push(make_pair(j, l));
                cnt++;
                while(!q.empty()){
                    for(int h = 0; h<4; h++){
                        new_x = q.front().first + X[h];
                        new_y = q.front().second + Y[h];
                        
                        if(new_x <0 || new_x >=m || new_y<0 || new_y >=n)
                            continue;
                        
                        if(map[new_x][new_y] == 0 || visit[new_x][new_y] == 1)
                            continue;
                        
                        visit[new_x][new_y] = 1;
                        q.push(make_pair(new_x, new_y));
                    }
                    q.pop();
                }
                
            }
        }
        printf("%d\n", cnt);
    }
}
