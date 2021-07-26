#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<int> answer;
map<string, int> m;
int parent[10000];

void dfs(int idx, int money){
    if(idx == -1)
        return;
    
    int give = money/10;
    answer[idx] += (money - give);
    
    if(give < 1)
        return;
    
    dfs(parent[idx], give);
    
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    answer.resize(enroll.size());
    
    for (int i = 0; i < enroll.size(); i++) {
        m[enroll[i]] = i;
    }
    
    for (int i = 0; i < referral.size(); i++) {
        if (referral[i] == "-") {
            parent[i] = -1;
        }
        else {
            parent[i] = m[referral[i]];
        }
    }
    
    for(int i=0; i<seller.size(); i++){
        dfs(m[seller[i]], amount[i]*100);
    }
    
    return answer;
}
