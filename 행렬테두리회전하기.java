class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int querySize = queries.length;
        int[] answer = new int[querySize];
        int[][] board = new int[rows][columns];
        int[][] temp = new int[rows][columns];      //회전 임시저장
        
        //행렬 생성
        int num = 1;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                board[i][j] = num;
                temp[i][j] = num;
                num++;
            }
        }
        for(int i=0; i<querySize; i++){
            int x1 = queries[i][0]-1;
            int y1 = queries[i][1]-1;
            int x2 = queries[i][2]-1;
            int y2 = queries[i][3]-1;
            
            
            int minNum = board[x1][y1];
            // 가로: 맨 윗줄, 맨 아래줄 최솟값 확인
            for(int j=y1; j<=y2; j++){
                if (minNum > board[x1][j])
                    minNum = board[x1][j];
                if (minNum > board[x2][j])
                    minNum = board[x2][j];
            }
            
            //세로 : 맨 왼쪽 줄, 맨 오른쪽줄 최솟값 확인
            for(int j=x1; j<=x2; j++){
                if (minNum > board[j][y1])
                    minNum = board[j][y1];
                if (minNum > board[j][y2])
                    minNum = board[j][y2];
            }
            
            //회전 수행: 맨 위 가로 ->
            for(int j=y1+1; j<=y2; j++){
                temp[x1][j] = board[x1][j-1];
            }
            //회전 수행: 맨 아래 가로 ->
            for(int j=y1; j<=y2-1; j++){
                temp[x2][j] = board[x2][j+1];
            }
            
            //회전 수행: 맨 왼쪽 세로
            for(int j=x1; j<=x2-1; j++){
                temp[j][y1] = board[j+1][y1];
            }
            
            //회전 수행: 맨 오른쪽 세로
            for(int j=x1+1; j<=x2; j++){
                temp[j][y2] = board[j-1][y2];
            }
            
            //board 배열에 회전 적용
            for(int k=0; k<rows; k++){
                for(int j=0; j<columns; j++){
                    board[k][j] = temp[k][j];
                }
            }
            
            
            answer[i]=minNum;
        }
        return answer;
    }
}
