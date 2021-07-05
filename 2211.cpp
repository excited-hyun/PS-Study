#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> way[1001];   //pos, cost
int cost[1001];
int path[1001];
priority_queue<pair<int, int>> pq;  //cost, pos
int n, m;

void dijkstra(){
    int here, here_c;
    int there, there_c;
    
    for(int i=0; i<=n; i++)
        cost[i] = -1;
    pq.push(make_pair(0, 1));
    
    while(!pq.empty()){
        here = pq.top().second;
        here_c = -pq.top().first;
        pq.pop();
        
        for(int i=0; i<way[here].size(); i++){
            there = way[here][i].first;
            there_c = way[here][i].second + here_c;
            
            if(cost[there]==-1 || cost[there] > there_c){
                cost[there]= there_c;
                path[there] = here;
                pq.push(make_pair(-there_c, there));
            }
        }
    }
    
    printf("%d\n", n-1);
    for(int i=2; i<=n; i++){
        printf("%d %d\n", path[i], i);
    }
}

int main(void){

    int a, b, cost;
    
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &cost);
        way[a].push_back(make_pair(b, cost));
        way[b].push_back(make_pair(a, cost));
        
    }
    dijkstra();
}

