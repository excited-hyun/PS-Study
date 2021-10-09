#include <cstdio>
#include <queue>

using namespace std;

int moveR[4] = {1, -1 , 0, 0};
int moveC[4] = {0, 0 , 1, -1};

int main () {
    int R, C, N;
    queue<pair<int, int>> q;
    
    scanf("%d %d %d", &R, &C, &N);
    char map[R][C];
    
    for(int i=0; i<R; i++){
        getchar();
        for(int j=0; j<C; j++){
            scanf("%c", &map[i][j]);
        }
    }
    
    // 2의 배수 초 후엔 항상 모든 칸에 폭탄
    if(N%2 == 0){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                printf("O");
            }
            printf("\n");
        }
        return 0;
    }
    
    
    int now = 1;
    
    while(now < N){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(map[i][j] == 'O'){
                    q.push(make_pair(i, j));
                }
            }
        }
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                map[i][j] = 'O';
            }
        }
        
        while(!q.empty()){
            
            int nowR = q.front().first;
            int nowC = q.front().second;
            q.pop();
            map[nowR][nowC ] = '.';
            for(int i=0; i<4; i++){
                int nextR = nowR+moveR[i];
                int nextC = nowC+moveC[i];
                
                if(nextR<0 || nextR>=R || nextC<0 || nextC>=C)
                    continue;
                map[nextR][nextC] = '.';
            }
        }
        
        
        now+=2;
        
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
