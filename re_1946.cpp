#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>> p_order;
priority_queue<pair<int, int>> v_order;

int main(void){
    int tc;
    int n;
    int paper, view;
    int pass_v;
    int pass=0;
    
    scanf("%d", &tc);
    
    for(int j=0; j<tc; j++){
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d %d", &paper, &view);
            p_order.push(make_pair(-paper, -view));
        }
        
        pass = 0;
        
        paper = -p_order.top().first;
        view = -p_order.top().second;
        p_order.pop();
        v_order.push(make_pair(-view, paper));
        pass++;
        
        while(!p_order.empty()){
            paper = -p_order.top().first;
            view = -p_order.top().second;
            p_order.pop();
            
            pass_v = -v_order.top().first;
            
            if(view < pass_v){
                pass++;
            }
            v_order.push(make_pair(-view, paper));
        }
        
        while(!v_order.empty()){
            v_order.pop();
        }
        printf("%d\n", pass);
        
    }
}
