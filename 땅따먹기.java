class Solution {
    int solution(int[][] land) {
        int answer = 0;
        int len = land.length;
        int[][] dp = new int [len][4];
        
        //dp[0][] 초기화
        for(int i=0; i<4; i++){
            dp[0][i] = land[0][i];
        }
        //dp[1~len-1][]
        for(int i=1; i<len; i++){
            dp[i][0] = Math.max(Math.max(dp[i-1][1], dp[i-1][2]), dp[i-1][3]) + land[i][0];
            dp[i][1] = Math.max(Math.max(dp[i-1][0], dp[i-1][2]), dp[i-1][3]) + land[i][1];
            dp[i][2] = Math.max(Math.max(dp[i-1][0], dp[i-1][1]), dp[i-1][3]) + land[i][2];
            dp[i][3] = Math.max(Math.max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + land[i][3];
        }

        //맨 아래줄의 4개의 열중에 최댓값 찾기
        answer = Math.max(Math.max(dp[len-1][0], dp[len-1][1]), Math.max(dp[len-1][2], dp[len-1][3]));

        return answer;
    }
}
