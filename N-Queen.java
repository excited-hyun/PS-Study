import java.util.*;

class Solution {
    int answer = 0;
    
    public void queen(int[] qX, int[] qY, int cnt, int n){
        
        if(cnt == n){
            answer++;
            return;
        }
        for(int i=0; i<n; i++){
            int newX = cnt;
            int newY = i;
            int can = 1;
            
            for(int j=0; j<cnt; j++){
                int befX = qX[j];
                int befY = qY[j];
                
                //같은 세로줄에 이미 퀸이 있는 경우
                if(befY == newY){
                    can = 0;
                    break;
                }
                
                //대각선에 이미 퀸이 있는 경우
                if( ((newX-befX) == (newY-befY)) || ((newX-befX) == -(newY-befY)) ){
                    can = 0;
                    break;
                }
            }
            
            if(can == 1){
                qX[cnt] = newX;
                qY[cnt] = newY;
                queen(qX, qY, cnt+1, n);
            }
        }
    }
    
    public int solution(int n) {
        
        int[] qX = new int[n];
        int[] qY = new int[n];
        
        for(int i=0; i<n; i++){
            qX[0] = 0;
            qY[0] = i;
            queen(qX, qY, 1, n);
        }
        
        return answer;
    }
}
