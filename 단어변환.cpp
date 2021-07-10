#include <string>
#include <vector>

using namespace std;

int check[50];
int min_change = 10000;

//변환 가능한지 확인
int change(string from, string to) {
    int cnt=0;
    
    for(int i=0; i<from.length(); i++){
        if(from[i]!=to[i])
            cnt++;
    }
    //불가능
    if(cnt != 1)
        return -1;
    return 1;
}

//DFS
void solve(int cnt, string now, string target, vector<string> words) {
    
    //target과 같아짐
    if(now == target){
        if(cnt < min_change)
            min_change = cnt;
        return;
    }
    
    
    for(int i=0; i<words.size(); i++){
        //이미 변환 or 변환 불가
        if(check[i] != 0 || change(now, words[i]) != 1)
            continue;
        check[i] = 1;
        solve(cnt+1, words[i], target, words);  //다음!
        check[i] = 0;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    solve(0, begin, target, words);
    
    //변환이 아예 불가능
    if(min_change == 10000)
        answer = 0;
    else
        answer =  min_change;
    
    return answer;
}
