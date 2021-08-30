import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        int len = times.length;
        Arrays.sort(times);
        long minT = 1;
        long maxT = (long)n * (long)times[len-1];   //반드시 (long)써주기!!!
        
        //이분탐색 시작
        while(minT < maxT){
            long midT = (minT+maxT)/2;
            long sum = 0;                   //midT 시간동안 심사받는 사람
            
            for(int i=0; i<len; i++){
                sum += midT/times[i];
                if(sum > n)                 //n보다 커지면 더이상 안더해도 됨
                    break;
            }
            
            if(sum < n)
                minT = midT+1;
            else
                maxT = midT;
        }
        answer = Math.min(minT, maxT);
        return answer;
    }
}
