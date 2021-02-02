#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dist[1001][1001];

priority_queue<pair<int ,int>> pq;
vector<vector<pair<int, int>>> way;

int main(void){
    int n, m, x;
    int city_a, city_b;
    int here, cost;
    int there, nextCost;
    int max = 0;
    
    scanf("%d %d %d", &n, &m, &x);

    way.resize(n+1);
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &city_a, &city_b, &cost);
        way[city_a].push_back(make_pair(city_b, cost));
    }

    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = -1;
        }
    }
    for(int j=1; j<=n; j++){
        //가는길
        dist[j][j] = 0;
        pq.push(make_pair(0, j));

        while(!pq.empty()){
            cost = -1 * pq.top().first;
            here = pq.top().second;
            pq.pop();
        
            if(dist[j][here] < cost)
                continue;
        
            for(int i=0; i<way[here].size(); i++){
                
                there = way[here][i].first;
                nextCost = cost + way[here][i].second;
            
                if(dist[j][there]==-1){
                    dist[j][there] = nextCost;
                    pq.push(make_pair(-nextCost, there));

                }
                else if(nextCost < dist[j][there]){
                    dist[j][there] = nextCost;
                    pq.push(make_pair(-nextCost, there));
                }
            }
            
        }
        
    }
    
    for(int i=1; i<=n; i++){
        if(dist[i][x] + dist[x][i] > max)   //가는길 + 오는길
            max = dist[i][x] + dist[x][i];
    }
    
    printf("%d\n", max);
    
    
}
