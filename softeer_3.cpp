#include<iostream>
#include<cstdio>

using namespace std;

int main(int argc, char** argv)
{
    int k, n;
    int min;
    int bef;
    int now;
    int keep;
    int w_time[101][101];
    int m_time[101][102];
    scanf("%d %d", &k, &n);
    
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            scanf("%d", &w_time[i][j]);
        }
        for(int j=1; j<=k; j++){
            scanf("%d", &m_time[i][j+1]);
        }
    }

    for(int j=1; j<=k; j++){
        scanf("%d", &w_time[n][j]);
    }
    
    min = w_time[1][1];
    now = 1;
    for(int j=1; j<=k; j++){
        if(min > w_time[1][j]){
            min =w_time[1][j];
            now = j;
        }
    }

    for(int i=1; i<n; i++){
        bef = min;
        min += w_time[i+1][now];
        keep = now;
        for(int j=1; j<=k; j++){
            if(j!=now){
                if(min > bef+ m_time[now][j]+w_time[i+1][j]){
                    min = bef+ m_time[now][j]+w_time[i+1][j];
                    keep = j;
                    
                }
            }
        }
        now = keep;
    }
    
    printf("%d\n", min);
    return 0;
}
