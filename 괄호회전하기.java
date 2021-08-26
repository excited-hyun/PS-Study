import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        int len = s.length();
        String move = "";
        
        for(int i=0; i<len; i++){
            //회전한 문자열 생성
            String newS = "";
            for(int j=i; j<len; j++)
                newS = newS + s.charAt(j);
            for(int j=0; j<i; j++)
                newS = newS + s.charAt(j);
            
            //올바른 괄호 문자열인지 확인
            if(check(newS))
                answer++;
            
        }
        return answer;
    }
    
    //올바른 괄호 문자열인지 확인하는 함수
    boolean check (String newS){
        Stack<Character> s = new Stack<Character>();
        int len = newS.length();
        for(int i=0; i<len; i++){
            //여는 괄호는 스택에 push
            if(newS.charAt(i) == '(')
                s.push(newS.charAt(i));
            else if(newS.charAt(i) == '[')
                s.push(newS.charAt(i));
            else if(newS.charAt(i) == '{')
                s.push(newS.charAt(i));
            
            //닫는 괄호는 스택의 top값과 비교
            else if(newS.charAt(i) == ')'){
                //여는 괄호 없이 닫는거 나옴
                if(s.empty())
                    return false;
                //짝이 안맞음
                if(s.peek() != '(')
                    return false;
                s.pop();
            }
            else if(newS.charAt(i) == ']'){
                if(s.empty())
                    return false;
                if(s.peek() != '[')
                    return false;
                s.pop();
            }
            else if(newS.charAt(i) == '}'){
                if(s.empty())
                    return false;
                if(s.peek() != '{')
                    return false;
                s.pop();
            }
                
        }
        //여는 괄호가 더 많은 경우 스택이 비지 않음
        if(!s.empty())
            return false;
        
        return true;
    }
}
