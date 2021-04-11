#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>> c_time;
priority_queue<pair<int, int>> r_time;

int main (void){
    int n;
    int s, e;
    int room_s, room_e;
    int room_cnt=0;
    scanf("%d", &n);
 
    for(int i=0; i<n; i++){
        scanf("%d %d",  &s, &e);
        c_time.push(make_pair(-s, -e));
        
    }
    s = -c_time.top().first;
    e = -c_time.top().second;
    
    c_time.pop();
    r_time.push(make_pair(-e, -s));
    room_cnt++;
    
    while(!c_time.empty()){
        s = -c_time.top().first;
        e = -c_time.top().second;
        c_time.pop();
        
        room_s = -r_time.top().second;
        room_e = -r_time.top().first;
        
        if(s < room_e){
            room_cnt++;
        }
        else{
            r_time.pop();
        }
        r_time.push(make_pair(-e, -s));
    }
    
    printf("%d\n", room_cnt);
}
