#include <string>
#include <vector>
#include <set>

using namespace std;
int answer = 0;
vector<string> added;

//유일성 확인 함수
bool check(string temp, vector<vector<string>> relation){
    vector<string> check;
    set<string> same;
    
    int tuple = relation.size();
    check.resize(tuple);
    
    //선택한 속성들을 가지고 각각의 튜플의 해당 속성 값을 string으로 연결
    for(int i=0; i<temp.length(); i++){
        for(int j=0; j<tuple; j++){
            check[j] += relation[j][temp[i]-'0'];
        }
    }
    //생성한 string중 중복값이 있는지 확인
    for(int i=0; i<tuple; i++){
        auto it = same.find(check[i]);
        if(it==same.end())
            same.insert(check[i]);
        //중복값 있는 경우 유일성 만족 X
        else
            return false;
    }
    return true;
}

void dfs(int idx, int cnt, int size, string now, vector<vector<string>> relation){
    //원하는 size길이의 속성 string생성 함.
    if(size == cnt){
        //유일성 만족하는 경우
        if(check(now, relation) == true){
            //최소성 확인 - 이미 added에 추가된 string들의 각 문자가 now에 포함되어 있는지 확인.
            for(int j=0; j<added.size(); j++){
                bool already = true;
                for(int i=0; i<added[j].size(); i++){
                    //문자 하나씩 포함 여부 확인
                    string str = added[j].substr(i, 1);
                    //added[j]의 string의 문자 중 now에 없는게 하나라도 있는 경우
                    if (now.find(str) == std::string::npos) {
                        already = false;
                        break;
                    }
                }
                //now가 이미 added에 포함된 string의 문자들을 원소로함 - 최소성 X
                if(already == true)
                    return ;
            }
            //유일성, 최소성 모두 만족
            added.push_back(now);
            answer++;
            return ;
        }
        
        //유일성 만족 X
        else{
            return ;
        }
    }
    //후보키 크기가 아직 작음
    else {
        int attribute = relation[0].size();
        for (int i=idx+1; i<attribute; i++){
            string temp = now+to_string(i);
            //재귀로 후보키 하나 더 추가
            dfs(i, cnt+1, size, temp, relation);
        }
    }
}

int solution(vector<vector<string>> relation) {
    
    int attribute = relation[0].size();
    //j 크기의 후보키를 i부터의 속성을 이용해 생성하게 하는 재귀.
    for (int j=1; j<=attribute; j++){
        for (int i=0; i<attribute; i++){
            string temp = ""+to_string(i);
            dfs(i, 1, j, temp, relation);
        }
    }
    return answer;
}
