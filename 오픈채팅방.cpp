#include <string>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m1;
    char cmd[10];
    char id[11];
    char name[11];
    for(int i=0; i<record.size(); i++){
        if (record[i][0] == 'E'){
            sscanf(record[i].c_str(), "%s %s %s", cmd, id, name);
            m1[id] = name;
        }
        else if (record[i][0] == 'C'){
            sscanf(record[i].c_str(), "%s %s %s", cmd, id, name);
            m1[id] = name;
        }
        else if (record[i][0] == 'L'){
            sscanf(record[i].c_str(), "%s %s", cmd, id);
        }
        
    }
    
    for(int i=0; i<record.size(); i++){
        if (record[i][0] == 'E'){
            sscanf(record[i].c_str(), "%s %s %s", cmd, id, name);
            answer.push_back(m1[id]+"님이 들어왔습니다.");
        }
        
        else if (record[i][0] == 'L'){
            sscanf(record[i].c_str(), "%s %s", cmd, id);
            answer.push_back(m1[id]+"님이 나갔습니다.");
        }
        
    }
   
    return answer;
}
