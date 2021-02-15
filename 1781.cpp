#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<pair<int ,int>> d_pq;
priority_queue<pair<int ,int>> c_pq;

queue<pair<int, int>> keep_q;

int main (void){
    int n;
    int a, b;
    int deadline, cup;
    int pop_c, pop_d;
    int comp_c;
    int time = 0;
    long long cnt = 0;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        d_pq.push(make_pair(-a, b));
    }
    while(!d_pq.empty()){
        deadline = -d_pq.top().first;
        cup = d_pq.top().second;
        
        d_pq.pop();
        if(time < deadline){    //일단은 현재 시간보다 데드라인 작은것 넣음
            time++;
            cnt+=cup;
            c_pq.push(make_pair(-cup, deadline));
        }
        else{       //현재시간이 데드라인보다 큰경우 이미 고른 것들중 가장 컵라면 적게주는 것들 뽑아 비교
            if(!c_pq.empty()){
                comp_c = 0;
                for(int i=0; i <= (time - deadline); i++){
                    pop_c = -c_pq.top().first;
                    pop_d = c_pq.top().second;
                    c_pq.pop();
                    
                    comp_c += pop_c;
                    keep_q.push(make_pair(pop_c, pop_d));
                    //printf("%d %d %d\n", comp_c, pop_c, time);
                }
                if(cup > comp_c){
                    cnt-=comp_c;
                    cnt+=cup;
                    time = deadline;
                    c_pq.push(make_pair(-cup, deadline));
                    while(!keep_q.empty())
                        keep_q.pop();
                }
                else{
                    while(!keep_q.empty()){
                        pop_c = keep_q.front().first;
                        pop_d = keep_q.front().second;
                        keep_q.pop();
                        //printf("%d %d %d\n", pop_d, pop_c, time);
                        c_pq.push(make_pair(-pop_c, pop_d));
                    }
                }
            }
        }
            
    }
    printf("%lld\n", cnt);
}
