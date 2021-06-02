#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int map[21][21];
int team[21];
int n;

int gap = 10000;

int cal_gap(){
    int team_s=0;
    int team_l=0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(team[i]==1 && team[j] == 1){
                team_s+=map[i][j];  //1이면 팀 스타트
            }
            else if(team[i] == 0 && team[j] == 0){
                team_l+=map[i][j];  //0이면 팀 링크
            }
        }
    }
    
    return abs(team_s - team_l);    //차의 절댓값
}

void dfs(int idx, int cnt){
    
    if(cnt == n/2){
        gap = min(gap, cal_gap());
    }
    
    if(idx == n+1)
        return;
    
    team[idx] = 1;      //팀 스타트에 넣음
    dfs(idx+1, cnt+1);
    
    team[idx] = 0;      //팀 링크에 넣음
    dfs(idx+1, cnt);
    
}

int main (void){

    
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            scanf("%d", &map[i][j]);
    }
    
    team[1] = 1;
    
    dfs(2, 1);
    
    printf("%d\n", gap);
    
}
