#include <cstdio>
#include <vector>

using namespace std;

int map[20][20];
int X[5] = {0, 0, 0, -1, 1};
int Y[5] = {0, 1, -1, 0, 0};
vector<int> dice(6);

int main() {
    int n, m, x, y, k;
    
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    int move;
    for(int i=0; i<k; i++){
        scanf("%d", &move);
        int newX = x+X[move];
        int newY = y+Y[move];
        
        if(newX<0 || newX>=n || newY<0 || newY>=m)
            continue;
        
        //동
        if(move == 1){
            
            dice = {dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]};
        }
        //서
        else if(move == 2){
            dice = {dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]};
        }
        
        //남
        else if(move == 3){
            dice = {dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]};
        }
        //북
        else if(move == 4){
            dice = {dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]};
        }
        
        if(map[newX][newY] == 0){
            map[newX][newY] = dice[5];
            
        }
        else{
            dice[5] = map[newX][newY];
            map[newX][newY] = 0;
        }
        
        printf("%d\n", dice[0]);
        
        x = newX;
        y = newY;
    }
    
    return 0;
    
}
