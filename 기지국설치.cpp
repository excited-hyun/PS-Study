#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;

void sol(int start, int last, int w){
    cnt++;
    if(last - start > w*2){
        start = start+w*2+1;
        sol(start, last, w);
    }
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    sort(stations.begin(), stations.end());
    int start = 1, last = 1;

    int sSize = stations.size();
    for(int i=0; i<sSize; i++){
        if(i==0){
            start = 1;
            last = stations[i]-w-1;
            if(start>last)
                continue;
            sol(start, last, w);
        }
        else {
            start = stations[i-1]+w+1;
            last = stations[i]-w-1;
            if(start>last)
                continue;
            sol(start, last, w);
            
        }
    }
    //마지막
    start = stations[sSize-1]+w+1;
    last = n;
    if(start<=last)
        sol(start, last, w);
    
    answer = cnt;

    return answer;
}
