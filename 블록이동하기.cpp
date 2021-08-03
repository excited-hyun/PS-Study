#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visit[2][101][101];     //0:가로, 1: 세로
queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q; //(r1, c1),(r2, c2), time

int solution(vector<vector<int>> board) {
    int answer = 0;
    int R[4] = {1, -1, 0, 0};
    int C[4] = {0, 0, 1, -1};
    int n = board.size();
    
    q.push(make_pair(make_pair(make_pair(0,0), make_pair(0,1)),0));
    visit[0][0][0] = 1;
    
    while(!q.empty()){
        int r1 = q.front().first.first.first;
        int c1 = q.front().first.first.second;
        int r2 = q.front().first.second.first;
        int c2 = q.front().first.second.second;
        int time = q.front().second;
        q.pop();
        
        if((r1 == n-1 && c1 == n-1) || (r2 == n-1 && c2 == n-1)){
            return time;
        }
        
        int check_dir;
        //가로
        if(r1 == r2)
            check_dir = 0;
        //세로
        else
            check_dir = 1;
        //상하좌우 이동 확인
        for(int i=0; i<4; i++){
            int next_r1 = r1+R[i];
            int next_c1 = c1+C[i];
            int next_r2 = r2+R[i];
            int next_c2 = c2+C[i];
            int check_r, check_c;
            if(next_r1 <0 || next_r1 >= n || next_c1 <0 || next_c1 >= n)
                continue;
            if(next_r2 <0 || next_r2 >= n || next_c2 <0 || next_c2 >= n)
                continue;
            if(board[next_r1][next_c1] ==1 || board[next_r2][next_c2] == 1)
                continue;
            
            //방문여부 확인
            if(next_r1 == next_r2){
                check_c = min(next_c1, next_c2);
                check_r = next_r1;
            }
            if(next_c1 == next_c2){
                check_r = min(next_r1, next_r2);
                check_c = next_c1;
            }
            if(visit[check_dir][check_r][check_c] == 1)
                continue;
            
            
            q.push(make_pair(make_pair(make_pair(next_r1,next_c1), make_pair(next_r2,next_c2)),time+1));
            visit[check_dir][check_r][check_c] = 1;
        }
        
        //회전 확인
        //가로
        if(check_dir == 0){
            int next_c1 = c2;
            int next_r1 = r1-1;
            //(r1, c1)이동
            if(next_r1 >=0 && !board[next_r1][c1] && !board[next_r1][c2] && !visit[1][next_r1][next_c1]){
                q.push(make_pair(make_pair(make_pair(next_r1,next_c1), make_pair(r2,c2)),time+1));
                visit[1][next_r1][next_c1]=1;
            }
            next_r1 = r1+1;
            if(next_r1 < n && !board[next_r1][c1] && !board[next_r1][c2] && !visit[1][r1][next_c1]){
                q.push(make_pair(make_pair(make_pair(next_r1,next_c1), make_pair(r2,c2)),time+1));
                visit[1][r1][next_c1]=1;
            }
            //(r2, c2) 이동
            int next_c2 = c1;
            int next_r2 = r2-1;
            if(next_r2 >=0 && !board[next_r2][c1] && !board[next_r2][c2] && !visit[1][next_r2][next_c2]){
                q.push(make_pair(make_pair(make_pair(r1,c1), make_pair(next_r2,next_c2)),time+1));
                visit[1][next_r2][next_c2]=1;
            }
            next_r2 = r2+1;
            if(next_r2 <n && !board[next_r2][c1] && !board[next_r2][c2] && !visit[1][r2][next_c2]){
                q.push(make_pair(make_pair(make_pair(r1,c1), make_pair(next_r2,next_c2)),time+1));
                visit[1][r2][next_c2]=1;
            }
        }
        
        //세로
        else{
            int next_c1 = c1-1;
            int next_r1 = r2;
            //(r1, c1)이동
            if(next_c1 >=0 && !board[r1][next_c1] && !board[r2][next_c1] && !visit[0][next_r1][next_c1]){
                q.push(make_pair(make_pair(make_pair(next_r1,next_c1), make_pair(r2,c2)),time+1));
                visit[0][next_r1][next_c1]=1;
            }
            next_c1 = c1+1;
            if(next_c1 < n && !board[r1][next_c1] && !board[r2][next_c1] && !visit[0][next_r1][c1]){
                q.push(make_pair(make_pair(make_pair(next_r1,next_c1), make_pair(r2,c2)),time+1));
                visit[0][next_r1][c1]=1;
            }
            
            //(r2, c2) 이동
            int next_c2 = c2-1;
            int next_r2 = r1;
            if(next_c2 >=0 && !board[r1][next_c2] && !board[r2][next_c2] && !visit[0][next_r2][next_c2]){
                q.push(make_pair(make_pair(make_pair(r1,c1), make_pair(next_r2,next_c2)),time+1));
                visit[0][next_r2][next_c2]=1;
            }
            next_c2 = c2+1;
            if(next_c2 < n && !board[r1][next_c2] && !board[r2][next_c2] && !visit[0][next_r2][c2]){
                q.push(make_pair(make_pair(make_pair(r1,c1), make_pair(next_r2,next_c2)),time+1));
                visit[0][next_r2][c2]=1;
            }
        }
    }
    
    
    return answer;
}
