#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int X[8] = {1, 2, -1, 1, -1, -2, 2, -2};
int Y[8] = {2, 1, 2, -2, -2, -1, -1, 1};
int visited[301][301];

queue<pair<pair<int, int>,int>> check;

int main(void){
    int tc;
    int n;
    int s_x, s_y;
    int f_x, f_y;
    int x, y;
    int n_x, n_y;
    int cnt;
    int result;
    
    scanf("%d", &tc);
    
    for(int i=0; i<tc; i++){
        scanf("%d", &n);
        scanf("%d %d", &s_x, &s_y);
        scanf("%d %d", &f_x, &f_y);
        
        if(s_x == f_x && s_y == f_y){
            printf("0\n");
            continue;
        }
        
        check.push(make_pair(make_pair(s_x, s_y), 0));
        visited[s_x][s_y] = 1;
        
        while(!check.empty()){
            x = check.front().first.first;
            y = check.front().first.second;
            cnt = check.front().second;
            if(x == f_x && y == f_y){
                result = cnt;
                break;
            }
            check.pop();
            
            for(int i=0; i<8; i++){
                n_x = x+X[i];
                n_y = y+Y[i];
                if(n_x <0 || n_x >=n || n_y<0 || n_y >=n)
                    continue;
                if(visited[n_x][n_y] == 1)
                    continue;
                check.push(make_pair(make_pair(n_x, n_y), cnt+1));
                visited[n_x][n_y] = 1;
            }
        }
        while(!check.empty())
            check.pop();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        printf("%d\n", result);
    }
}
