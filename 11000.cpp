#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int, int>> s_pq;    //시작시간 기준 오름차순
priority_queue<pair<int, int>> f_pq;    //종료시간 기준 오름차순


int main(void){
    int n;
    int s, f;
    int c_cnt;
    int sw;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &s, &f);
        s_pq.push(make_pair(-s, -f));
    }

    c_cnt = 1;
    
    s = -s_pq.top().first;
    f = -s_pq.top().second;
    s_pq.pop();
    f_pq.push(make_pair(-f, -s));
    
    while(!s_pq.empty()){
        s = -s_pq.top().first;
        f = -s_pq.top().second;
        s_pq.pop();
        sw = 0;
        if(s < -f_pq.top().first){
            c_cnt++;
            f_pq.push(make_pair(-f, -s));
        }
        else{
            f_pq.pop();
            f_pq.push(make_pair(-f, -s));
        }
    }
    printf("%d\n", c_cnt);
}
