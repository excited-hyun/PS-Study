#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
int card[1001];
int max_cost[1001];

int main(void){
    int n;
    
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &card[i]);
        max_cost[i] = card[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<= i/2; j++){
            if(max_cost[i] < max_cost[j] + max_cost[i-j])
                max_cost[i] = max_cost[j] + max_cost[i-j];
        }
    }
    printf("%d\n", max_cost[n]);
}
