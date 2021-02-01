#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int frd[50][50];
int connect[50];
int score[50];
int can_num;


int main(void){
    int n;
    int f1, f2;
    int F;
    int cnt=1;
    int min_score;
    int frd_cnt;
    queue<pair<int, int>> q;   //번호, 연결 수
    
    scanf("%d", &n);
    min_score = 50;
    
    while(1){
        scanf("%d %d", &f1, &f2);
        if(f1 == -1 && f2 == -1)
            break;
        frd[f1-1][f2-1] = 1;
        frd[f2-1][f1-1] = 1;
        
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            connect[j] = 0;
        }
        connect[i] = 1;
        frd_cnt = 1;
        cnt = 1;
        for(int j=0; j<n; j++){
            if(frd[i][j] == 1){
                q.push(make_pair(j, 1));
                connect[j] = 1;
                frd_cnt++;
            }
        }
        
        while(!q.empty()){
            F = q.front().first;
            for(int i=0; i<n; i++){
                if(frd[F][i] == 1 && connect[i] == 0){
                    connect[i] = 1;
                    frd_cnt++;
                    cnt = q.front().second+1;
                    q.push(make_pair(i,cnt));
                }
            }
            q.pop();
            
        }
        if(frd_cnt == n){
            score[i] = cnt;
            if(min_score > cnt)
                min_score = cnt;
        }
    }
    
    for(int i=0; i<n; i++){
        if(score[i] == min_score)
            can_num++;
    }
    printf("%d %d\n", min_score, can_num);
    for(int i=0; i<n; i++){
        if(score[i] == min_score)
            printf("%d ", i+1);
    }
    printf("\n");
}
