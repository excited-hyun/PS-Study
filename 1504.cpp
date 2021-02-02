#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dist[801];
vector<vector<pair<int, int>>> way;
priority_queue<pair<int, int>> pq; //비용, 위치

void dijkstra(int s, int n);

int main(void){
    int n, e, v1, v2;
    int a, b, c;
    int v1_v2;
    int v2_v1;
    int in_v1=0, in_v2=0;
    
    
    
    scanf("%d %d", &n, &e);
    
    
    way.resize(n+1);
    for(int i=0; i<e; i++){
        scanf("%d %d %d", &a, &b, &c);
        way[a].push_back(make_pair(b, c));
        way[b].push_back(make_pair(a, c));
    }
    scanf("%d %d", &v1, &v2);
    
    
    dijkstra(1, n);
    //v1->v2
    v1_v2 = dist[v1];
    //v2->v1
    v2_v1 = dist[v2];
    if(dist[v1] == -1 ){
        in_v1 = 1;
    }
    if(dist[v2] == -1){
        in_v2 = 1;
    }
   
    //v1->v2
    dijkstra(v1, n);
    v1_v2 +=dist[v2];
    if(dist[v2] == -1 ){
        in_v1 = 1;
    }
    dijkstra(v2, n);
    v1_v2 +=dist[n];
    if(dist[n] == -1 ){
        in_v1 = 1;
    }
    

    
    //v2->v1
    dijkstra(v2, n);
    v2_v1 +=dist[v1];
    if(dist[v1] == -1 ){
        in_v2 = 1;
    }
    dijkstra(v1, n);
    v2_v1 +=dist[n];
    if(dist[n] == -1 ){
        in_v2 = 1;
    }

    
    if(in_v1 != 1 && in_v2 !=1){
        if(v1_v2 < v2_v1)
            printf("%d\n", v1_v2);
        else
            printf("%d\n", v2_v1);
    }
    
    else if(in_v1 == 1 && in_v2 == 1){
        printf("-1\n");
    }
    
    else if(in_v1 == 1 && in_v2 == 0){
        printf("%d\n", v2_v1);
    }
    else if(in_v1 == 0 && in_v2 == 1){
        printf("%d\n", v1_v2);
    }
}

void dijkstra(int s, int n){
    int here, cost;
    int there, there_cost;
    
    for(int i=1; i<=n; i++){
        dist[i] = -1;
    }
    
    dist[s] = 0;
    
    pq.push(make_pair(0, s));
    
    while(!pq.empty()){
        cost = -pq.top().first;
        here = pq.top().second;
        pq.pop();
        if(dist[here] < cost)
           continue;
        
        for(int i=0; i<way[here].size(); i++){
            there = way[here][i].first;
            there_cost = cost + way[here][i].second;
            
            if(dist[there] == -1){
                dist[there] = there_cost;
                pq.push(make_pair(-there_cost, there));
            }
            else if( dist[there] > there_cost){
                dist[there] = there_cost;
                pq.push(make_pair(-there_cost, there));
            }
        }
    }
}
