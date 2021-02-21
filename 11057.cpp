#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int cnt[1001][10];

int main(void){
    int n;
    int sum = 0;
    scanf("%d", &n);
    for(int i=0; i<10; i++){
        cnt[1][i] = 1;
    }
    for(int i=2; i<=n; i++){
        cnt[i][0] = cnt[i-1][0] % 10007;
        for(int j=1; j<10; j++){
            cnt[i][j] = cnt[i][j-1] + cnt[i-1][j];
            cnt[i][j] %=10007;
        }
    }
    for(int i=0; i<10; i++){
        sum+=cnt[n][i];
    }
    printf("%d\n", sum%10007);
}
