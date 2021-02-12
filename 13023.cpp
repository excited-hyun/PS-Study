#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> frien;
int visit[2000];
int cnt;


void dfs(int s, int n);

int main(void){
    int n, m;
    int f_a, f_b;
    
    scanf("%d %d", &n, &m);
    frien.resize(n);
    for(int i=0; i<m; i++){
        scanf("%d %d", &f_a, &f_b);
        frien[f_a].push_back(f_b);
        frien[f_b].push_back(f_a);
    }
    
    for(int i=0; i<n; i++){
        cnt = 0;
        dfs(i, n);
    }
    printf("0\n");
}

void dfs(int s, int n){
    int there;
    cnt++;
    if(cnt == 5){
        printf("1\n");
        exit(0) ;
    }
    
    visit[s] = 1;
    for(int i=0; i<frien[s].size(); i++){
        there = frien[s][i];
        if(visit[there] == 1)
            continue;
        dfs(there, n);
    }
    cnt--;
    visit[s] =0;
}

