#include <string>
#include <vector>
#include <queue>

using namespace std;
queue<pair<pair<int, int>, pair<int, int>>> q; //r, c, 방향, cost
int cost[4][25][25];

//상하좌우
int R[4] = {-1, 1, 0, 0};
int C[4] = {0, 0, -1, 1};

void bfs(vector<vector<int>> board){
    int max_r = board.size();
    int max_c = max_r;
    
    //cost[][][] 초기화
    for(int i=0; i<4; i++){
        for(int j=0; j<max_r; j++){
            for(int k=0; k<max_c; k++){
                cost[i][j][k] = 999999999;
            }
        }
    }
    for (int i = 0; i < 4; i++)
        cost[i][0][0] = 0;
    
    //처음 이동 저장
    for(int i=0; i<4; i++){
        int r = R[i];
        int c = C[i];
        //범위 벗어남
        if(r<0 || c<0 || board[r][c] == 1)
            continue;
        cost[i][r][c] = 100;
        q.push(make_pair(make_pair(r, c), make_pair(i, 100)));
    }
    
    //경로확인
    while(!q.empty()){
        int now_r = q.front().first.first;
        int now_c = q.front().first.second;
        int now_dir = q.front().second.first;
        int now_cost = q.front().second.second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int next_r = now_r + R[i];
            int next_c = now_c + C[i];
            int next_cost = now_cost;
            //범위 벗어남
            if(next_r < 0 || next_r >= max_r || next_c <0 || next_c >= max_c){
                continue;
            }
            //벽
            if(board[next_r][next_c]==1)
                continue;
            
            next_cost += 100;
            //코너의 경우 500더 든다.
            if(i!=now_dir)
                next_cost += 500;
               
            
            //지금 cost가 기존의 cost보다 작은 경우
            if(cost[i][next_r][next_c] > next_cost){
                cost[i][next_r][next_c] = next_cost;
                q.push(make_pair(make_pair(next_r, next_c), make_pair(i, next_cost)));
            }
            
            
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int max_r = board.size();
    int max_c = max_r;
    
    bfs(board);

    //4방향중 최솟값 확인
    answer = 999999999;
    for(int i=0; i<4; i++){
        if(cost[i][max_r-1][max_c-1] < answer)
            answer = cost[i][max_r-1][max_c-1];
    }
    
    return answer;
}
