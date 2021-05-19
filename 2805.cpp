#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long tree[1000000];

void sol(int n, long long m){
    long long high = tree[n-1];
    long long low = 0;
    long long mid;
    long long min_diff = 1000000001;
    long long min_diff_h;
    long long total=0;


    while(high >= low){
        mid = (high + low) / 2;
        total = 0;
        //printf("%lld\n", mid);
        for(int i=0; i<n; i++){
            if(tree[i] > mid)
                total = total + (tree[i] - mid);
        }
        
        if(total > m) { //필요보다 많음
            if(min_diff > total - m){
                min_diff = total - m;
                min_diff_h = mid;
            }
            low = mid+1;
    
        }
        else if (total < m) //필요보다 적음
            high = mid -1;
        
        else{
            printf("%lld\n", mid);
            return ;
        }
    }
    printf("%lld\n", min_diff_h);
    
}

int main (void) {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    
    for(int i=0; i<n; i++){
        scanf("%lld", &tree[i]);
    }
    
    sort(tree, tree+n);
    
    sol(n, m);
    
}
