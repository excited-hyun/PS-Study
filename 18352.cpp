#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dist[300001];
vector< vector<int> > way;

int main(void){
    int n, m, k, x;
    int city_a, city_b;
    int here, cost;
    int there, nextCost;
    int cnt =0;

    priority_queue<pair<int ,int>> pq;
    
    scanf("%d %d %d %d", &n, &m, &k, &x);
    way.resize(n+1);
    for(int i=0; i<m; i++){
        scanf("%d %d", &city_a, &city_b);
        way[city_a].push_back(city_b);
    }
    
    for(int i=1; i<=n; i++){
        dist[i] = n;
    }
    
    dist[x] = 0;
    pq.push(make_pair(0, x));

    while(!pq.empty()){
        cost = -1 * pq.top().first;
        here = pq.top().second;
        pq.pop();
        
        if(dist[here] < cost)
            continue;
        
        for(int i=0; i<way[here].size(); i++){
            
            there = way[here][i];
            nextCost = cost + 1;
            
            if(nextCost < dist[there]){
                dist[there] = nextCost;
                pq.push(make_pair(-nextCost, there));

            }
            
        }
    }
    for(int i=1; i<=n; i++){
        if(dist[i] == k){
            printf("%d\n", i);
            cnt++;
        }
    }
    if(cnt == 0){
        printf("-1\n");
    }
    
}
