class Solution {
    public int solution(int sticker[]) {
        int answer = 0;
        int len = sticker.length;
        
        //스티커 하나 or 두개인 경우 처리
        if(len == 1)
            return sticker[0];
        else if(len == 2)
            return Math.max(sticker[0], sticker[1]);
        int[][] dp = new int[2][len];
        
        dp[0][0] = sticker[0];
        dp[0][1] = dp[0][0];    //첫번째 스티커 사용O
        dp[1][0] = 0;
        dp[1][1] = sticker[1];  //첫번째 스티커 사용X
        
        for(int i=2; i< len-1; i++){
            dp[0][i] = Math.max(dp[0][i-2]+sticker[i], dp[0][i-1]);
            dp[1][i] = Math.max(dp[1][i-2]+sticker[i], dp[1][i-1]);
        }
        
        //첫번째 스티커 안썼으니까 마지막 가능
        dp[1][len-1] = Math.max(dp[1][len-3]+sticker[len-1], dp[1][len-2]);
        answer = Math.max(dp[0][len-2], dp[1][len-1]);
        
        return answer;
    }
}
