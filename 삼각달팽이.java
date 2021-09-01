class Solution {
    public int[] solution(int n) {
        int size = (n+1)*n/2;
        
        int[] answer = new int[size];
        int[][] temp = new int[n][n];
        int num = 1;
        int r = -1;
        int c = 0;
        
        size = n;
        while(n>0){
            //아래 대각선
            for(int i=0; i<n; i++){
                r++;
                temp[r][c] = num;
                num++;
                
            }
            
            n--;
            if(n==0)
                break;

            //오른쪽
            for(int i=0; i<n; i++){
                c++;
                temp[r][c] = num;
                num++;
            }
            n--;
            if(n==0)
                break;
            
            //위로 대각선
            for(int i=0; i<n; i++){
                r--;
                c--;
                temp[r][c] = num;
                num++;
            }
            n--;
            if(n==0)
                break;
        }
        
        //temp값을 answer에 옮기기
        int idx = 0;
        for(int i=0; i<size; i++) {
			for(int j=0; j<size; j++) {
				if(temp[i][j] == 0) {
					break;
				}
				answer[idx] = temp[i][j];
				idx ++;
			}
		}
            
        return answer;
    }
}
