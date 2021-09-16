#include <cstdio>
#include <queue>

using namespace std;

int map[100][100];
int headR=0, headC=0;

int R[4] = {0, 1, 0, -1};
int C[4] = {1, 0, -1, 0};
int dir = 0;
queue<pair<int, int>> q;

int main() {
    int n, k, l;
    scanf("%d", &n);
    scanf("%d", &k);
    
    map[0][0] = -1;     //뱀이 있는 위치
    for(int i=0; i<k; i++){
        int r, c;
        scanf("%d %d", &r, &c);
        map[r-1][c-1] = 1;
    }
    
    scanf("%d", &l);
    int now = 0;
    q.push(make_pair(0, 0));
    for(int i=0; i<l; i++){
        int x;
        char c;
        scanf("%d %c", &x, &c);
        //회전 시간이 될 때 까지
        while(now < x){
            headR += R[dir];
            headC += C[dir];
            now++;
            
            if(headR<0 || headR>=n || headC<0 || headC>=n){
                printf("%d\n", now);
                return 0;
            }
            //이동하면 머리 위치 큐에 넣어줌
            q.push(make_pair(headR, headC));
            if(map[headR][headC] == -1){
                printf("%d\n", now);
                return 0;
            }
            //사과O : 꼬리 안옮겨도 됨.
            if(map[headR][headC] == 1){
                map[headR][headC] = -1;
                continue;
            }
            
            //사과X : 꼬리 옮겨야 함.
            map[headR][headC] = -1;
            int tailR = q.front().first;
            int tailC = q.front().second;
            q.pop();
            map[tailR][tailC] = 0;      //꼬리가 있던 위치 비우기
        }
        //방향 전환
        //왼
        if(c == 'L'){
            dir--;
            if(dir == -1)
                dir = 3;
        }
        //오
        if(c == 'D'){
            dir++;
            if(dir == 4)
                dir = 0;
        }
    }
    // 더 이상 회전 없음 -> 그 방향으로만 이동
    while(1){
        headR += R[dir];
        headC += C[dir];
        now++;
        
        if(headR<0 || headR>=n || headC<0 || headC>=n){
            break;
        }
        q.push(make_pair(headR, headC));
        if(map[headR][headC] == -1){
            break;
        }
        if(map[headR][headC] == 1){
            map[headR][headC] = -1;
            continue;
        }
        map[headR][headC] = -1;
        int tailR = q.front().first;
        int tailC = q.front().second;
        q.pop();
        map[tailR][tailC] = 0;
    }
    printf("%d\n",now);
    
    return 0;
}
