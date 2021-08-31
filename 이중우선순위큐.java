import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {0, 0};
        int cnt = 0;
        PriorityQueue<Integer> pq1 = new PriorityQueue<>(); //큰 값이 top
        PriorityQueue<Integer> pq2 = new PriorityQueue<>(); //작은 값이 top
        
        for(String data : operations){
            if(data.charAt(0) == 'I'){
                cnt++;
                String num = data.substring(2);
                int n = Integer.parseInt(num);
                pq1.add(-n);
                pq2.add(n);
            }
            else if(data.charAt(0) == 'D'){
                if(cnt == 0)
                    continue;
                
                //최솟값 삭제
                if(data.charAt(2) == '-'){
                    pq2.remove();
                }
                //최댓값 삭제
                else{
                    pq1.remove();
                }
                cnt--;
                if(cnt == 0){
                    pq1.clear();
                    pq2.clear();
                }
            }
        }
        if(cnt == 1){
            answer[0] = pq2.peek();
            answer[1] = answer[1];
        }
        else if(cnt > 1){
            answer[0] = -pq1.peek();
            answer[1] = pq2.peek();
        }
        return answer;
    }
}
