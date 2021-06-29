#include <iostream>
#include <queue>
using namespace std;

priority_queue <pair<int, int>> pq;
vector<vector<pair<int, int>>> map;
int cost[1001];

int main() {
    int a, b;
    int n, m;
    int s, e;
    
    scanf("%d %d", &a, &b);
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<=n; i++){
        cost[i] = -1;
    }
    map.resize(n+1);
    for (int i=0; i<m; i++){
        scanf("%d %d", &s, &e);
        map[s].push_back(make_pair(e, 1));
        map[e].push_back(make_pair(s, 1));
    }
    cost[a] = 0;
    pq.push(make_pair(0, a));
    
    while(!pq.empty()){
        int c = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(c> cost[here])
            continue;
        
        for(int i=0; i<map[here].size(); i++){
            int there = map[here][i].first;
            int there_c = c + map[here][i].second;
            
            if(cost[there] == -1){
                cost[there] = there_c;
                pq.push(make_pair(-there_c, there));
            }
            else if(cost[there] > there_c){
                cost[there] = there_c;
                pq.push(make_pair(-there_c, there));
            }
        }
    }
    printf("%d\n", cost[b]);
}
