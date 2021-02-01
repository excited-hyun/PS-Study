#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dist[1001];
vector<vector<pair<int, int>>> way;

int main(void){
    int n, m, s, g;
    int city_a, city_b;
    int here, cost;
    int there, nextCost;

    priority_queue<pair<int ,int>> pq;
    
    scanf("%d", &n);
    scanf("%d", &m);
    way.resize(n+1);
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &city_a, &city_b, &cost);
        way[city_a].push_back(make_pair(city_b, cost));
    }
    scanf("%d %d", &s, &g);
    
    for(int i=1; i<=n; i++){
        dist[i] = -1;
    }
    
    dist[s] = 0;
    pq.push(make_pair(0, s));

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
    
    printf("%d\n", dist[g]);
    
    
}
