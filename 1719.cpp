#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;


priority_queue<pair<int, int>> pq; //cost,pos
vector<vector<pair<int, int>>> way;

int cost[201];
int path[201];

int main(void){

    int n, m;
    int a, b, d;
    
    int here, here_c;
    int there, there_c;
    
    
    scanf("%d %d", &n, &m);
    way.resize(n+1);
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &d);
        way[a].push_back(make_pair(b, d));
        way[b].push_back(make_pair(a, d));
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cost[j] = -1;
        }
    
        cost[i] = 0;
        pq.push(make_pair(0, i));
        
        while(!pq.empty()){
            here_c = -pq.top().first;
            here = pq.top().second;
            pq.pop();
            
            if(here_c> cost[here])
                continue;
            
            for(int j=0; j<way[here].size(); j++){
                there = way[here][j].first;
                there_c = here_c + way[here][j].second;
                
                if(cost[there] == -1){
                    path[there] = here;
                    cost[there] = there_c;
                    pq.push(make_pair(-there_c, there));
                }
                else if(cost[there] > there_c){
                    path[there] = here;
                    cost[there] = there_c;
                    pq.push(make_pair(-there_c, there));
                }
                
            }
        }
        
        for (int j = 1; j <= n; j++) {
            if (j == i)
                printf("- ");
            else
            {
                int index = j;
                while (1)
                {
                    if (path[index] == i)
                    {
                        printf("%d ", index);
                        break;
                    }
                    else
                        index = path[index];
                }
            }
        }
        printf("\n");
        
    }
    
    
}
