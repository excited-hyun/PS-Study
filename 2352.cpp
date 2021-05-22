#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> result;

void insert(int port){
    int low = 0;
    int high = result.size()-1;
    int mid;
    
    while(high >= low){
        mid = (high + low)/2;
        if(result[mid] < port)
            low = mid + 1;
        else
            high = mid-1;
    }
    
    result[low] = port;
    
}

int main (void){
    int n, port;
    int idx=0;
    
    scanf("%d", &n);
    
    scanf("%d", &port);
    result.push_back(port);
    
    for(int i=1; i<n; i++){
        scanf("%d", &port);
        
        if(port > result[idx]){
            result.push_back(port);
            idx++;
        }
        else{
            insert(port);
        }
    }
    printf("%d\n", result.size());
}
