#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int max(int a, int b) {if (a > b) return a; return b;}

int v[101];
int w[101];
int bag[101][100001];

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if (j >= w[i]) //물건 담을 수 있음
                bag[i][j] = max(bag[i - 1][j], bag[i - 1][j - w[i]] + v[i]);
                        
            else
                bag[i][j] = bag[i - 1][j];
        }
    }
    printf("%d\n", bag[n][k]);
}
