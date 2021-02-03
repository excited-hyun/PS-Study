#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int cost[100001];
int X[2] = {-1, 1};

priority_queue<pair<int, int>> pq; //비용, 위치

int main(void){
    int n, k;
    int here, h_time;
    int there, t_time;
    
    scanf("%d %d", &n, &k);
    
    for(int i=0; i<100001; i++){
        cost[i] = -1;
    }
    pq.push(make_pair(0, n));
    cost[n] = 0;
    
    while(!pq.empty()){
        h_time = -pq.top().first;
        here = pq.top().second;
        pq.pop();
        
        if(h_time > cost[here])
            continue;
        for(int i=0; i<3; i++){
            if( i== 2){
                there = 2*here;
                t_time = h_time;
            }
            else{
                there = here+ X[i];
                t_time = h_time+1;
            }
            if(there < 0 || there > 100000)
                continue;
            
            if(cost[there] == -1){
                cost[there] = t_time;
                pq.push(make_pair(-t_time, there));
            }
            else if(cost[there] > t_time){
                cost[there] = t_time;
                pq.push(make_pair(-t_time, there));
            }
        }
    }
    printf("%d\n", cost[k]);
}
