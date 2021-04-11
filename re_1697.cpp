#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int total_move;
int visited[100001];

int X[2] = {-1, 1};
queue<pair<int, int>> check;

int main(void){
    int n, k;
    int p_x, n_x;
    int cnt;
    int result;

    scanf("%d %d", &n, &k);
    
    if(n== k){
        printf("0\n");
        return 0;
    }
    
    check.push(make_pair(n, 0));
    visited[n] = 0;
    
    while(!check.empty()){
        p_x = check.front().first;
        cnt = check.front().second;
        check.pop();
        if(p_x == k){
            result = cnt;
        }
        
        for(int i=0; i<3; i++){
            if(i==2){
                n_x = p_x*2;
            }
            else{
                n_x = p_x+X[i];
            }
            if(n_x < 0 | n_x > 100000)
                continue;
            if(visited[n_x] == 1)
                continue;
            check.push(make_pair(n_x, cnt+1));
            visited[n_x] = 1;
        }
    }
    printf("%d\n", result);
    
}
