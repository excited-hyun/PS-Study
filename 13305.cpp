#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int dist[100000];
int cost[100000];

int main(void){
    int n;
    long long total=0;
    long long c_now;
    
    scanf("%d", &n);
    
    for(int i=1; i<n; i++){
        scanf("%d", &dist[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &cost[i]);
    }
    c_now = cost[0];
    total = c_now * dist[1];
    //첫번째->두번째 이동
    
    for(int i=1; i<n; i++){
        if(c_now < cost[i]){
            total += c_now * dist[i+1];
        }
        else{
            c_now = cost[i];
            total += c_now*dist[i+1];
        }
    }
    printf("%lld\n", total);
}
