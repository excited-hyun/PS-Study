#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> pq;
    int hot1, hot2;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(-scoville[i]);
    }
    
    while(pq.size()>=2 && -pq.top() < K){
        hot1 = -pq.top();
        pq.pop();
        hot2 = -pq.top();
        pq.pop();
        
        pq.push(-(hot1 + hot2*2));
        answer++;
    }
    if(-pq.top() < K)
        answer = -1;
    return answer;
}
