#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
stack<pair<int, int>> s;
vector<int> v;

int main(void){
    int n;
    int h;
    int min;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &h);
        min = 0;
        while(!s.empty()){
            if(s.top().first > h){
                v.push_back(s.top().second);
                break;
            }
            s.pop();
        }
        
        if(s.empty()){
            v.push_back(0);
        }
        
        s.push(make_pair(h, i+1));
        
    }
    
    
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}
