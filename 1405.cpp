#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int visited[30][30];
double per[4]; //동서남북
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

double per_sum;
int cnt;

void dfs(int x, int y, double now_per);

int main (void){

    int s_x, s_y;
    
    scanf("%d %lf %lf %lf %lf", &n, &per[0], &per[1], &per[2], &per[3]);
    
    s_x = n;
    s_y = n;
    
    dfs(s_x, s_y, 1.0);
    
    printf("%.10lf\n", per_sum);
}

void dfs(int x, int y, double now_per){
    int next_x, next_y;
    double next_per;
    visited[x][y] = 1;
    if(cnt == n){
        per_sum += now_per;
        visited[x][y] = 0;
        return;
    }
    cnt++;
    for(int i=0; i<4; i++){
        next_x = x+X[i];
        next_y = y+Y[i];
        if(visited[next_x][next_y]==1)
            continue;
        next_per = now_per * (per[i] / 100);
        //printf("<%d %d> <%d %d> %lf\n", x, y, next_x, next_y, next_per);
        dfs(next_x, next_y, next_per);
    }
    
    visited[x][y] = 0;
    cnt--;
}
