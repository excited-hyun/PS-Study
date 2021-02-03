#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int weight[1000];

priority_queue<int> pq;

int main(void){
    int n, w;
    int sum = 1;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &w);
        pq.push(-w);
    }
    for(int i=0; i<n; i++){
        weight[i] = -pq.top();
        pq.pop();
    }
    for(int i=0; i<n; i++){
        if(sum < weight[i])
            break;
        sum += weight[i];
    }
    printf("%d\n", sum);
}
