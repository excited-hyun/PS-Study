#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> check;
    int w = 0;
    int round = 1;
    char bef;
    
    while(w < words.size()){
        for(int i=1; i<=n; i++){
            //첫번째 사람은 확인X
            if(i==1 && w==0){
                
                int len = words[w].length()-1;
                bef = words[w][len];
                check.push_back(words[w]);
                w++;
                continue;
            }
            
            //이미 사용한 단어인지 확인
            string used = words[w];
            auto it = find(check.begin(), check.end(), used);
            if (it != check.end()){
                answer.push_back(i);
                answer.push_back(round);
                return answer;
            }
            
            //앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말한지 확인
            if(bef != words[w][0]){
                answer.push_back(i);
                answer.push_back(round);
                return answer;
            }
            
            int len = words[w].length()-1;
            bef = words[w][len];
            
            check.push_back(words[w]);
            w++;
            
            //탈락자 안 생김
            if(w == words.size()){
                answer.push_back(0);
                answer.push_back(0);
                return answer;
            }
        }
        round++;
    }
    
    
    
    return answer;
}
