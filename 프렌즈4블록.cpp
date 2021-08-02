#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool del;
    vector<string> temp;
    temp.resize(board.size());
    copy(board.begin(), board.end(), temp.begin());
    
    while(1){
        copy(board.begin(), board.end(), temp.begin());
        del = false;
        
        //제거 가능한 블록 찾기
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(board[i][j] == '.')
                    continue;
                
                //4블록!->삭제
                if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]){
                    temp[i][j] = '.';
                    temp[i][j+1] = '.';
                    temp[i+1][j] = '.';
                    temp[i+1][j+1] = '.';
                    del = true;
                }
            }
        }
        
        //더이상 제거 불가 -> while문 종료
        if(del == false)
            break;
        
        //board에 빈칸 표시
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][j] == '.') {
                    board[i][j] = '.';
                }
            }
        }
        
        //블록 내리기
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (int k = i; k > 0; k--) {
                        if (board[k - 1][j] == '.')
                            break;
                        board[k][j] = board[k - 1][j];
                        board[k - 1][j] = '.';
                    }
                }
            }
        }

    }
    
    //삭제된 블록 모두 세기
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') {
                answer++;
            }
        }
    }

    return answer;
}
