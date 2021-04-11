#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> pq;

int main(void){
    int n;
    int c_size;
    int c_one, c_two;
    int temp_sum;
    int sum = 0;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &c_size);
        pq.push(-c_size);
    }
    while(1){
        c_one = -pq.top();
        pq.pop();
        if(pq.empty())
            break;
        c_two = -pq.top();
        pq.pop();
        temp_sum = c_one + c_two;
        pq.push(-temp_sum);
        sum+= temp_sum;
        
    }
    printf("%d\n", sum);
}
