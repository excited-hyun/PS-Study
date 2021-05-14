#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cube[21];

long long cnt;

void sol(int l, int w, int h, int c_idx){
    //printf("%d %d %d %d %lld\n", l, w, h, c_idx, cnt);
    int flag = 0;
    int k;
    int a;
    if(l==0 || w==0 || h==0)
        return ;

    k = min({l, w, h});
    c_idx = log2(k);
    
    for(int i=c_idx; i>=0; i--){
        if( cube[i]>0){
            c_idx = i;
            flag = 1;
            break;
        }
        
    }
   
    if(flag == 0){
        printf("-1\n");
        exit(0);

    }
    
    a=pow(2, c_idx);
    cnt++;
    cube[c_idx]--;
    sol(l-a, w, h, c_idx);
    sol(a, w, h-a, c_idx);
    sol(a, w- a, a, c_idx);

}

int main(void){
    int l, w, h;
    int n;
    int a, b;
    
    scanf("%d %d %d", &l, &w, &h);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        cube[a] = b;
        
    }
    
    sol(l, w, h, n-1);
    printf("%lld\n", cnt);
}
