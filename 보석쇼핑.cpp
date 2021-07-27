#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>


using namespace std;
queue<string> q;
map<string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int g_type, start = 0, end = 1000001, tmp = 0;
    
    for(auto i : gems)
        m[i] = 0;
    g_type = m.size();
    m.clear();
    
    for(int i=0; i<gems.size(); i++){
        m[gems[i]]++;
        
        q.push(gems[i]);
        
        while(1)
        {
            if(m[q.front()] > 1)
            {
                m[q.front()] -= 1;
                q.pop();
                tmp++;
            }
            else
                break;
        }
        
        if(m.size() == g_type && end > q.size())
        {
            end = q.size();
            start = tmp;
        }
    }
    
    answer.push_back(start + 1);
    answer.push_back(start + end);
    return answer;
}
