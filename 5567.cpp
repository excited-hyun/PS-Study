#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int frd[500][500];
int con[500];

int main(void){
    int n, m;
    int f1, f2;
    int F;
    int cnt=0;
    queue<int> q;
    
    scanf("%d", &n);
    scanf("%d", &m);
    
    con[0] = 1;
    for(int i=0; i<m; i++){
        scanf("%d %d", &f1, &f2);
        frd[f1-1][f2-1] = 1;
        frd[f2-1][f1-1] = 1;
        if(f1 == 1){
            q.push(f2-1);
            con[f2-1] = 1;
            cnt++;
        }
        if(f2 == 1){
            q.push(f1-1);
            con[f1-1] = 1;
            cnt++;
        }
    }
    while(!q.empty()){
        F = q.front();
        
        for(int i=1; i<n; i++){
            if(frd[F][i] == 1 && con[i] == 0){
                con[i] = 1;
                cnt++;
            }
        }
        q.pop();
    }
    printf("%d\n", cnt);
    
}
