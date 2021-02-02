#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;


priority_queue<pair<int, int>> pq;  //비용, 컴퓨터

int cost[10001];

int main(void){
    int test;
    int n, d, c;
    int a, b, s;
    
    int here, here_c;
    int there, there_c;
    int cnt, time;
    
    scanf("%d", &test);
    for(int k=0; k<test; k++){
        
        vector<vector<pair<int, int>>> way; //컴퓨터a, 비용
        cnt = 0;
        time = 0;
        scanf("%d %d %d", &n, &d, &c);
        way.resize(n+1);
        
        for(int i=0; i<d; i++){
            scanf("%d %d %d", &a, &b, &s);
            way[b].push_back(make_pair(a, s));
        }
        for(int i=1; i<=n; i++){
            cost[i] = -1;
        }
        cost[c] = 0;
        
        
        pq.push(make_pair(0, c));
        
        while(!pq.empty()){
            here_c = -pq.top().first;
            here = pq.top().second;
            pq.pop();
            
            if(here_c> cost[here])
                continue;
            
            for(int i=0; i<way[here].size(); i++){
                there = way[here][i].first;
                there_c = here_c + way[here][i].second;
                
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
        for(int i=1; i <= n; i++){
            if(cost[i] != -1){
                cnt++;
                if(time < cost[i])
                    time = cost[i];
            }
            
        }
        printf("%d %d\n", cnt, time);
        
    }
}
