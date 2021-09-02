class Solution
{
    public int solution(int [][]board)
    {
        int answer = 1;

        int r = board.length;
        int c = board[0].length;
        
        //표가 전부 0으로 이루어진지 확인
        int zero = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == 1)
                    break;
                zero++;
            }
        }
        //모두 0인 경우
        if(zero == r*c)
            return 0;
        
        //가장 큰 정사각형 구하기
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                if(board[i][j] == 0)
                    continue;
                board[i][j] = Math.min(Math.min(board[i-1][j],board[i][j-1]), board[i-1][j-1])+1;
                if(board[i][j] > answer)
                    answer = board[i][j];
            }
        }
        
        //넓이
        answer = answer*answer;

        return answer;
    }
}
