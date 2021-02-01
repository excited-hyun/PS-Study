#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int visit[1000001];

int main(void){
    int f, s, g, u, d;
    int x[2];
    int pos, move;
    int total;
    queue <pair<int ,int>> q; //위치, 이동회횟수
    
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    
    x[0] = u;
    x[1] = -1*d;
    
    visit[s] = 1;
    if(s == g){
        printf("0\n");
        return 0;
    }
    q.push(make_pair(s, 0));
    
    while(!q.empty()){
        for(int i=0; i<2; i++){
            pos = q.front().first + x[i];
            if(pos < 1 || pos > f)
                continue;
            if(visit[pos] == 1)
                continue;
            visit[pos] = 1;
            move = q.front().second + 1;
            total = move;
            q.push(make_pair(pos,move));
            if(pos == g){
                printf("%d\n", total);
                return 0;
            }
        }
        q.pop();
    }
    printf("use the stairs\n");
    
}
