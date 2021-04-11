#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int sen[10000];
int diff[10000];

int main(void){
    int n, k;
    int len=0;
    
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &sen[i]);
    }
    sort(sen, sen+n);
    for(int i=1; i<n; i++){
        diff[i-1] = sen[i]-sen[i-1];
    }
    sort(diff, diff+n);
    for(int i=0; i<n-k+1; i++){
        len += diff[i];
    }
    printf("%d\n", len);
}
