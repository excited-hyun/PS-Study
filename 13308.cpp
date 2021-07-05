#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

long long int dp[2501][2501];
int oil[2501];
int n, m;

vector <pair<int, int>> way[2501];
priority_queue<pair<long long int, pair<int, int>>> pq;     //cost, pos, oil price

void dijkstra(){
    int here, there, here_o, there_o;
    long long int here_c, there_c;
    long long int min_c;

    for(int i=0; i<=n; i++)
        for(int j=0; j<2501; j++)
            dp[i][j] = -1;
    pq.push(make_pair(0, make_pair(1, oil[1])));
    
    while(!pq.empty()){
        here = pq.top().second.first;
        here_c = -pq.top().first;           //here까지 비용
        here_o = pq.top().second.second;    //here까지의 최소 오일값
        pq.pop();
        
        if(dp[here][here_o] != -1)
            continue;
        
        dp[here][here_o] = here_c;
        
        if(here == n){      //도착!
            min_c = here_c;
            //printf("!!%d\n", n);
            break;
        }
        for(int i=0; i<way[here].size(); i++){
            there = way[here][i].first;
            there_c = way[here][i].second * min(here_o, oil[here]) + here_c;    //there까지 비용
            there_o = min(here_o, oil[here]);               //이번 이동에 쓰인 오일 값
            
            
            if(dp[there][there_o] == -1 ){
                pq.push(make_pair(-there_c, make_pair(there, there_o)));
            }
        }
        
    }
    
    printf("%lld\n", min_c);
}

int main(void) {
    int a, b, cost;
    
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &oil[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &cost);
        way[a].push_back(make_pair(b, cost));
        way[b].push_back(make_pair(a, cost));
    }
    dijkstra();
}

