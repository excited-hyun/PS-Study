#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int pick[100001];
int team[100001];
int visit[100001];
int can;
int start;
int cnt;

void dfs(int here);

int main(void){
    int t;
    int n;
    
    scanf("%d", &t);
    for(int j=0; j<t; j++){
        scanf("%d", &n);

        for(int i=1; i<=n; i++){
            scanf("%d", &pick[i]);
            team[i] = 0;
            visit[i] =0;
        }

        cnt = 0;
        for(int i=1; i<=n; i++){
            
            if(visit[i] == 0){
                start = i;
                can = 0;
                dfs(i);
            }
        }
        
        printf("%d\n", n-cnt);
    }
}

void dfs(int here){
    if(visit[here] == -1 || team[here] == 1){
        return ;
    }
    if(visit[here] == 0)
        visit[here] = 1;
    else if(visit[here] == 1){
        team[here] = 1;
        cnt++;
    }
    
    
    dfs(pick[here]);
    visit[here] = -1;
        
}
