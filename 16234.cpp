#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

int n, l, r;
int map[50][50];
int country[50][50];
int visited[50][50];

int R[4] = {1, -1, 0, 0};
int C[4] = {0, 0, 1, -1};

int main () {
    scanf("%d %d %d", &n, &l, &r);
    int ans = 0;
    int idx = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            country[i][j] = idx;
            idx++;
            scanf("%d", &map[i][j]);
        }
    }
    
    while(1){
        int move = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(visited[i][j] == 0){
                    queue<pair<pair<int, int>, int>> q;
                    queue<pair<pair<int, int>, int>> q2;
                    q.push(make_pair(make_pair(i, j), country[i][j]));      //BFS에 사용
                    q2.push(make_pair(make_pair(i, j), country[i][j]));     //인구 이동에 사용
                    
                    visited[i][j] = country[i][j];      //방문시 연결된 나라 번호 저장
                    int cnt = 1;                    //연결된 나라 수
                    int total = map[i][j];          //연결된 나라 총 인구수
                    
                    while(!q.empty()){
                        int nowR = q.front().first.first;
                        int nowC = q.front().first.second;
                        int num = q.front().second;
                        q.pop();
                        for(int i=0; i<4; i++){
                            int nextR = nowR + R[i];
                            int nextC = nowC + C[i];
                            if(nextR<0 || nextR>=n || nextC<0 || nextC>=n)
                                continue;
                            if(visited[nextR][nextC]!=0)
                                continue;
                            
                            //연결 가능
                            if( (abs(map[nowR][nowC] - map[nextR][nextC]) >= l) && (abs(map[nowR][nowC] - map[nextR][nextC]) <= r)){
                                cnt++;
                                total += map[nextR][nextC];
                                move++;
                                q.push(make_pair(make_pair(nextR, nextC), num));
                                q2.push(make_pair(make_pair(nextR, nextC), num));
                                visited[nextR][nextC] = num;
                            }
                        }
                    }
                    
                    //인구 이동 시킴
                    while(!q2.empty()){
                        int nowR = q2.front().first.first;
                        int nowC = q2.front().first.second;
                        q2.pop();
                        map[nowR][nowC] = total / cnt;
                    }
                }
            }
        }
        //인구 이동이 일어나지 않음 -> 종료
        if(move == 0)
            break;
        
        ans++;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
    }
    printf("%d\n", ans);
    
}
