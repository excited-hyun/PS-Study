#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define LIMIT 1000000000

int n, k, budget;
vector<pair<int, pair<int, int>>> way[101]; //pos, cost, dist
priority_queue<pair<int, pair<int, int>>> pq; //dist, pos, cost
int dist[101][10001];

void dijkstra(){
    int here, here_c, here_d;
    int there, there_c, there_d;
    int min_d;
    for(int i=0; i<=n; i++)
        for(int j=0; j<10001; j++)
            dist[i][j] = LIMIT;
    
    pq.push(make_pair(0, make_pair(1, 0)));
    dist[1][0] = 0;
    
    while(!pq.empty()){
        here = pq.top().second.first;
        here_c = pq.top().second.second;
        here_d = -pq.top().first;
        pq.pop();
        
        if(dist[here][here_c] < here_d)
            continue;
        
        for(int i=0; i<way[here].size(); i++){
            there = way[here][i].first;
            there_c = way[here][i].second.first + here_c;
            there_d = way[here][i].second.second + here_d;
            
            if(there_c > budget)
                continue;
            
            if(dist[there][there_c] <= there_d)
                continue;
            
            
            dist[there][there_c] = there_d;
            pq.push(make_pair(-there_d, make_pair(there, there_c)));
            
        }
    }
    min_d = LIMIT;
    for (int i = 1; i <= budget; i++){
        min_d = min(min_d, dist[n][i]);
    }
    if (min_d == LIMIT)
        printf("Poor KCM\n");
    else
        printf("%d\n", min_d);
    
  
}

int main (void){
    int tc;
    int a, b, cost, dist;
    
    scanf("%d", &tc);
    for(int i=0; i<tc; i++){
        scanf("%d %d %d", &n, &budget, &k);
        
        for(int j=0; j<k; j++){
            scanf("%d %d %d %d", &a, &b, &cost, &dist);
            way[a].push_back(make_pair(b, make_pair(cost, dist)));
            
        }
        
        dijkstra();
        
        for(int j=0; j<101; j++){
            way[j].clear();
        }
        while(!pq.empty())
            pq.pop();
        
    }
}


