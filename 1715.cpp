#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

priority_queue <pair<int, int>> pq;

int main(void){
    int n, card;
    int c1, c2, temp, sum=0;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &card);
        pq.push(make_pair(-card,i));
    }
    
    if(n==1){
        printf("0\n");
        return 0;
    }
    
    while(!pq.empty()){
        c1 = -pq.top().first;
        pq.pop();
        sum+=c1;
        
        c2 = -pq.top().first;
        pq.pop();
        sum+= c2;
        temp = c1 + c2;
        
        if(pq.empty())
            break;
        
        cnt++;
        pq.push(make_pair(-temp, cnt));
    }
    printf("%d\n", sum);
}
