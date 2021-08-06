class Solution {
    
    public long solution(int n) {
        long answer = 0;
        long[] way = new long[2001];
        
        way[1] = 1;
        way[2] = 2;
        
        for(int i=3; i<=n; i++){
            way[i] = way[i-1]+way[i-2];
            way[i] %= 1234567;
        }
        
        answer = way[n];
        
        return answer;
    }
}
