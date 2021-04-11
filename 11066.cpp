#include <iostream>
#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int ch[501];
int sum[501];
int tb[501][501];
int MIN = 5000000;

int main (void){
    int t, n;
    int cnt;
    int seq;
    
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        cnt = 0;
        for(int j=1; j<=n; j++){
            scanf("%d", &ch[j]);
            sum[j] = sum[j - 1] + ch[j];
        }
        
        for(int j=1; j<n; j++){
            for(int k=1; k<=n-j; k++){
                seq = k+j;
                tb[k][seq] = INT_MAX;
                for (int l=k; l<seq; l++){
                    tb[k][seq] =min(tb[k][seq], tb[k][l] + tb[l + 1][seq] + sum[seq] - sum[k - 1]);
                }
            }
        }
        printf("%d\n", tb[1][n]);
    }
}
