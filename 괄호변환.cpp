#include <string>
#include <vector>
#include <stack>

using namespace std;

//올바른 괄호인지 확인
bool check(string str){
    stack<char> s;
    for(int i=0; i<str.length(); i++){
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')'){
            if(s.empty())
                return false;
            s.pop();
        }
    }
    return true;
}

//재귀로 구현한 단계들
string solve(string str){
    
    string u = "", v = "";
    int open=0, close=0;
    
    //빈 문자열인지
    if(str=="")
        return "";
    //올바른 괄호인지
    if(check(str))
        return str;
    
    for(int i=0; i<str.length(); i++){
        if(str[i] == '('){
            open++;
            u = u+str[i];
        }
        else{
            close++;
            u = u+str[i];
        }
        
        //u를 균형잡힌 문자열로 만들었음
        if(open == close){
            //u가 올바른 문자열
            if(check(u)){
                v = str.substr(i+1);
                return u+solve(v);
            }
            //u가 올바른 문자열이 아님
            else{
                v = str.substr(i+1);
                string temp = "";
                temp += "(";
                temp = temp + solve(v);     //v에 대해 1단계부터 반복
                temp = temp+")";
                
                //u의 맨앞 맨뒤 제거
                u = u.substr(1, u.length()-2);
                //뒤집어서 추가
                for (int j = 0; j < u.length(); j++) {
                    if (u[j] == '(')
                        temp = temp + ')';
                    else
                        temp = temp + '(';
                }
                return temp;
            }
                
        }
        
    }
}

string solution(string p) {
    string answer = "";
    
    answer = solve(p);
    
    return answer;
}
