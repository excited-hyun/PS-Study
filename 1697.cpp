#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int total_move;
int visit[100001];

int x[3] = {-1, 1, 0};

int main(void){
    int n, k;
    int X;
    queue<pair<int, int>> m; //위치,
    scanf("%d %d", &n, &k);
    
    m.push(make_pair(n, 0));
    if ( n== k){
        printf("0\n");
        return 0;
    }
    visit[n] = 1;
    while(!m.empty()){
        for(int i=0; i<3; i++){
            if(i==2){
                X = m.front().first * 2;
            }
        
            else{
                X = m.front().first + x[i];
            }
            if(X<0 || X > 100000)
                continue;
            if(visit[X] == 1 )
                continue;
            
            visit[X] = 1;
            m.push(make_pair(X, m.front().second +1));
            total_move = m.front().second +1;
            
            if( X == k){
                printf("%d\n", total_move);
                
            }
        }
        m.pop();
    }
}
