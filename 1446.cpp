#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dist[10001];
vector <pair<int, int>> cost[10001];

int main () {
    int n, d;
    int s, e, c;
    int b;
    scanf("%d %d", &n, &d);
    
    for (int i=1; i<=d; i++)
        dist[i] = i;
    
    for( int i=0; i<n; i++){
        scanf("%d %d %d", &s, &e, &c);
        if(e-s <= c || e>d)
            continue;
        cost[s].push_back(make_pair(e, c));
        
    }
    
    
    for(int i=0; i<=d; i++){
        if(i==0)
            b = -1;
        else
            b = dist[i-1];
        dist[i] = min(dist[i],b + 1);
        //printf("%d %d\n", i-1, dist[i-1]);
        if(!cost[i].empty()){
            for(int j=0; j<cost[i].size(); j++){
                e = cost[i][j].first;
                c = cost[i][j].second;
          
                if(dist[i]+c < dist[e]){
                    dist[e] = dist[i] + c;
                }
            }
        }
    }
    
    printf("%d\n", dist[d]);
}


