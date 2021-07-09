#include <string>
#include <vector>
#include <set>

using namespace std;
int visited[10];
set<string> s;

void solve(int ban_idx, vector<string> user_id, vector<string> banned_id){
    //모든 불량사용자 아이디에 대해 제재 사용자 찾음
    if(ban_idx == banned_id.size()){
        string temp = "";
        for(int i=0; i<user_id.size(); i++)
            if(visited[i]==1)
                temp+=to_string(i); //해당 제재 사용자의 인덱스 넣어줌
        s.insert(temp);
        return ;
    }
    
    for(int i=0; i<user_id.size(); i++){
        int flag = 1;
        if(banned_id[ban_idx].length() != user_id[i].length())      //길이가 다르면 절대 해당할 수 없음
            continue;
        
        if(visited[i] == 1) //이미 다른 불량아이디로 목록에 주가되어 있음
            continue;
        for(int j=0; j<user_id[i].length(); j++){   //해당하는지 확인
            if(banned_id[ban_idx][j] == '*')
                continue;
            if(banned_id[ban_idx][j] != user_id[i][j]){ //다르면 바로 끝냄
                flag = 0;
                break;
            }
        }
        
        //해당하는 제재 아이디 찾은 경우
        if(flag == 1){
            visited[i]=1;       //목록에 넣어줌을 표시
            solve(ban_idx+1, user_id, banned_id);       //다음 불량사용자 아이디에 대해 수행
            visited[i]=0;       
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    solve(0, user_id, banned_id);
    answer = s.size();
    return answer;
}
