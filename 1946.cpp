#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    int t;
    int n, p, m;
    int m_min=0;
    int cnt;
    
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        priority_queue<pair<int, int>> pq;
        
        scanf("%d",&n);
        cnt = n;
        for(int j=0; j<n; j++){
            scanf("%d %d", &p, &m);
            pq.push(make_pair(-p, m));
        }
        
        p = -pq.top().first;
        m = pq.top().second;
        m_min = m;
        pq.pop();
        
        for(int j=1; j<n; j++){
            p = -pq.top().first;
            m = pq.top().second;
            pq.pop();
            if(m > m_min){
                cnt--;
            }
            else{
                m_min = m;
            }
            
        }
        
        printf("%d\n", cnt);
    }

}
