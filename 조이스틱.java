import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        int len = name.length();
        
        int move = len-1;
        for(int i=0; i<len; i++){
            //상하 이동
            //'O'~'Z'의 경우
            if(name.charAt(i) > 'N'){
                answer += 'Z' - name.charAt(i) +1;
            }
            //'A'~'N'의 경우
            else{
                answer += name.charAt(i) - 'A';
            }
            
            int conA = i+1;
            //다음 글자부터 연속된 A가 있는 경우 되돌아가는게 빠른지 확인
            while(conA < len && name.charAt(conA) == 'A'){
                conA++;
            }
            move = Math.min(move, i+len-conA+i);
                
        }
        answer+=move;
    
        return answer;
    }
}
