#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int water[1000];
priority_queue<int> pq;

int main(void){
    int n, l;
    
    int start;  //테이프 붙이는 시작점
    int cnt=0; //필요한 테이프 수
    scanf("%d %d", &n, &l);
    for(int i=0; i<n; i++){
        scanf("%d", &water[i]);
        pq.push(-water[i]);
    }
    
    //정렬된 순서가 아님
    for(int i=0; i<n; i++){
        water[i] = -pq.top();
        pq.pop();
        //printf("%d ", water[i]);
    }
        
    
    start = water[0];
    cnt++;
    
    for(int i=1; i<n; i++){
        if((water[i] - start) > (l-1)) {//하나의 테이프로 막기 불가능
            cnt++;
            start = water[i];   //시작점 바꿔줌
        }
            
    }
    printf("%d\n", cnt);
}
