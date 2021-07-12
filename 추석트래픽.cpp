#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> s_time;
    vector<int> f_time;
    for(int i=0; i<lines.size(); i++)
    {
        int fin=0;
        int start=0;
        
        fin+=stoi(lines[i].substr(11,2))*60*60*1000; //완료시간
        fin+=stoi(lines[i].substr(14,2))*60*1000;
        fin+=stoi(lines[i].substr(17,2))*1000;
        fin+=stoi(lines[i].substr(20,3));
        
        start=fin-(int)((stod(lines[i].substr(24)))*1000-1);
        
        s_time.push_back(start);
        f_time.push_back(fin);
        
    }
    int cnt;
    for(int i=0; i<s_time.size(); i++){
        cnt = 0;
 
        int range = s_time[i] - 999;
            
        for (int j = 0; j < s_time.size(); j++)
        {
            if (range <= s_time[j] && s_time[j] <= s_time[i])
                cnt++;
            else if (range >= s_time[j] && f_time[j] >= range)
                cnt++;
        }
        answer = max(answer, cnt);
    }
    
    return answer;
}
