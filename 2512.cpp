#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

long long money[10001];

void sol(int n, long long m){
    int low = 0;
    int high = n;
    int mid;
    long long be_mid=0;
    long long max_money;
    while(high >= low){
        be_mid = 0;
        mid = (high+low)/2;
        for(int i=0; i<mid; i++){
            be_mid+=money[i];
        }
        if (be_mid > m){
            high = mid-1;
        }
        else{
            max_money = m - be_mid;
            if(mid == n){
                printf("%lld\n", money[n-1]);
                exit(0);
            }
            max_money = max_money / (n-mid);
            
            if (money[mid-1] > max_money){
                high = mid-1;
            }
            else if (money[mid] < max_money){
                low = mid+1;
            }
            else{
                printf("%lld\n", max_money);
                exit(0);
            }
        }
    }
}

int main (void) {
    int n;
    long long m;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &money[i]);
    }
    scanf("%lld", &m);
    sort(money, money+n);
    sol(n, m);
}
