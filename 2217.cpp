#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int, int>> pq;
int arr[100000];

int main(void){

    int n;
    int w;
    int i;
    int max = 0;
    int temp;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        scanf("%d", &w);
        pq.push(make_pair(w, i));
    }
    
    i=0;
    while(!pq.empty()){
        
        arr[i] = pq.top().first;
        i++;
        pq.pop();
    }
    
  

    for(i=1; i<=n; i++){
        temp = arr[i-1]*i;
        if(temp > max)
            max = temp;
  
    }
    
    printf("%d\n", max);
}
