class Solution {
    
    int answer = -1;

    public int solution(int N, int number) {
        if(N==number)
            return 1;
        
        dfs(0, 0, number, N);        
        return answer;
    }

    private void dfs(int cnt, int now, int number, int N) {
        if (cnt > 8) 
            return ;
        
        //number 만들었음!
        if (now == number) {
            if(answer == -1 || answer > cnt)
                answer = cnt;
            return ;
        }

        //사칙연산 뿐만 아니라 NN...N도 처리해야함!!!
        int nn = N;
        for (int i = 0; i < 8 - cnt; i++) {
            dfs(cnt+i+1, now + nn, number, N);
            dfs(cnt+i+1, now - nn, number, N);
            dfs(cnt+i+1, now / nn, number, N);
            dfs(cnt+i+1, now * nn, number, N);

            nn = nn * 10 + N;
        }
    }
}
