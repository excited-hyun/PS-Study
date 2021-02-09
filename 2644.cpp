#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void dfs(int n, int now, int per_b);

int family[101][101];
int visit[100];
int cnt = -1;
int sol = -1;

int main(void){
    int n, m;
    int per_a, per_b;
    int p, c;

    scanf("%d", &n);
    scanf("%d %d", &per_a, &per_b);
    scanf("%d", &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &p, &c);
        family[p][c] = 1;
        family[c][p] = 1;
    }
    
    dfs(n, per_a, per_b);
    
    printf("%d\n", sol);
}

void dfs(int n, int now, int per_b){
    visit[now] = 1;
    cnt++;
    if(now == per_b){
        sol = cnt;
        return;
    }

    for(int i=1; i<=n; i++){
        if(visit[i] == 1)
            continue;
        if(family[now][i] == 0)
            continue;
        dfs(n, i, per_b);
    }
    cnt--;
}
