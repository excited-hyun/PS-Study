#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long cnt[101][10];

int main(void){
    int n;
    long sum=0;
    scanf("%d", &n);
    for(int i=1; i<10; i++){
        cnt[1][i] = 1;
    }
    for(int i=2; i<=n; i++){
        cnt[i][0] = cnt[i-1][1]%1000000000;
        cnt[i][9] = cnt[i-1][8]%1000000000;
        for(int j=1; j<9; j++){
            cnt[i][j] = (cnt[i-1][j-1]+cnt[i-1][j+1])%1000000000;
        }
    }
    for(int i=0; i<10; i++){
        sum+=cnt[n][i];
    }
    printf("%ld\n", sum%1000000000);
}
