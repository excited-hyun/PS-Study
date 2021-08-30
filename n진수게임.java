import java.util.*;

class Solution {
    public String solution(int n, int t, int m, int p) {
        HashMap <Integer, String> m1 = new HashMap<Integer, String> ();
        m1.put(0, "0"); m1.put(1, "1"); m1.put(2, "2"); m1.put(3, "3");
        m1.put(4, "4"); m1.put(5, "5"); m1.put(6, "6"); m1.put(7, "7");
        m1.put(8, "8"); m1.put(9, "9"); m1.put(10, "A"); m1.put(11, "B");
        m1.put(12, "C"); m1.put(13, "D"); m1.put(14, "E"); m1.put(15, "F");
        
        
        String answer = "";
        int num = 1;
        String total = "0";    //진법 변환한 값 이어붙임
        int cnt = 1;         //total길이
        while(true){
            int len = 0;        //변환한 길이
            String tmp = "";    //num 진법 변환
            int now = num;
            //진법 변환
            while(now > 0) {
                int r = now % n;
                now = now / n;
                tmp = m1.get(r) + tmp;
                len ++;
            }
            total = total + tmp;
            cnt += len;
            num++;
            
            //total의 길이가 m*t에 도달함
            if(cnt >= m*t)
                break;
        }
        
        //t개 뽑기
        for(int i=0; i<t; i++){
            answer += total.charAt(m*i + p -1);
        }
        return answer;
    }
}
