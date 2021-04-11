#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int map[101][101];
int visited[101];
queue<pair<int, int>> check;

int main(void){
    int n, m;
    int sol_x, sol_y;
    int p, c;
    int chon = -1;
    int find = -1;
    int result;
    
    scanf("%d", &n);
    scanf("%d %d", &sol_x, &sol_y);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &p, &c);
        map[p][c] = 1;
        map[c][p] = 1;
    }
    check.push(make_pair(sol_x, 0));
    
    while(!check.empty()){
        c = check.front().first;
        chon = check.front().second;
        check.pop();
        if(c == sol_y){
            find = 1;
            result = chon;
            break;
        }
        visited[c] = 1;
        chon++;
        for(int i=1; i<=n; i++){
            if(map[c][i] == 1 && visited[i] != 1)
                check.push(make_pair(i, chon));
        }

    }
    if(find == -1)
        printf("-1\n");
    else
        printf("%d\n", result);
    
}
