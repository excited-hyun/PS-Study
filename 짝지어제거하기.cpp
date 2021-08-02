#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> del;
    int s_len = s.length();
        
    for(int i=0; i<s_len; i++){
        if(del.empty())
            del.push(s[i]);
        
        else{
            char check = del.top();
            if(check == s[i])
                del.pop();
            else
                del.push(s[i]);
        }
    }

    if(del.empty())
        answer = 1;
    
    return answer;
}
