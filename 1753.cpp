#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dist[20001];
vector<vector<pair<int, int>>> way;

int main(void){
    int v, e, k;
    int city_a, city_b;
    int here, cost;
    int there, nextCost;

    priority_queue<pair<int ,int>> pq;
    
    scanf("%d %d", &v, &e);
    scanf("%d", &k);
    way.resize(v+1);
    for(int i=0; i<e; i++){
        scanf("%d %d %d", &city_a, &city_b, &cost);
        way[city_a].push_back(make_pair(city_b, cost));
    }
    
    for(int i=1; i<=v; i++){
        dist[i] = -1;
    }
    
    dist[k] = 0;
    pq.push(make_pair(0, k));

    while(!pq.empty()){
        cost = -1 * pq.top().first;
        here = pq.top().second;
        pq.pop();
        
        if(dist[here] < cost)
            continue;
        
        for(int i=0; i<way[here].size(); i++){
            
            there = way[here][i].first;
            nextCost = cost + way[here][i].second;
            
            if(dist[there]==-1){
                dist[there] = nextCost;
                pq.push(make_pair(-nextCost, there));

            }
            else if(nextCost < dist[there]){
                dist[there] = nextCost;
                pq.push(make_pair(-nextCost, there));
            }
            
        }
    }
    for(int i=1; i<=v; i++){
        if(dist[i] == -1)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
    
}
