#include <cstdio>

int cctv[8][2];

int map[10][10];
int n, m;
int ccCnt;
int minC = 100;

int checkRight(int r, int c){
    int cnt = 0;
    for(int i=c+1; i<m; i++){
        if(map[r][i] == 0){
            map[r][i] = -1;
            cnt++;
        }
        if(map[r][i] == 6)
            break;
        
    }
    return cnt;
}

int checkLeft(int r, int c){
    int cnt = 0;
    for(int i=c-1; i>=0; i--){
        if(map[r][i] == 0){
            map[r][i] = -1;
            cnt++;
        }
        if(map[r][i] == 6)
            break;
    }
    return cnt;
}
int checkUp(int r, int c){
    int cnt = 0;
    
    for(int i=r-1; i>=0; i--){
        if(map[i][c] == 0){
            map[i][c] = -1;
            cnt++;
        }
        if(map[i][c] == 6)
            break;
    }
    return cnt;
}
int checkDown(int r, int c){
    int cnt = 0;
    for(int i=r+1; i<n; i++){
        if(map[i][c] == 0){
            map[i][c] = -1;
            cnt++;
        }
        if(map[i][c] == 6)
            break;
    }
    return cnt;
}

void check(int idx){
    
    if(idx == ccCnt){
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == 0)
                    cnt++;
            }
        }
        if(cnt < minC){
            minC = cnt;
        }
        return;
    }
    
    int r = cctv[idx][0];
    int c = cctv[idx][1];
    
    int temp[10][10];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            temp[i][j] = map[i][j];
        }
    }
    
    if(map[r][c] == 1){
        int num;
        for(int i=0; i<4; i++){
            if(i == 0)
                num = checkRight(r, c);
            if(i == 1)
                num = checkLeft(r, c);
            if(i == 2)
                num = checkUp(r, c);
            if(i == 3)
                num = checkDown(r, c);
            
            check(idx+1);
            
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    map[i][j] = temp[i][j];
                }
            }
        }
        
    }
    else if(map[r][c] == 2){
        int num;
        for(int i=0; i<2; i++){
            if(i == 0){
                num = checkRight(r, c);
                num += checkLeft(r, c);
            }
            if(i == 1){
                num = checkUp(r, c);
                num += checkDown(r, c);
            }
            
            check(idx+1);
            
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    map[i][j] = temp[i][j];
                }
            }
        }
    }
    
    else if(map[r][c] == 3){
        int num;
        for(int i=0; i<4; i++){
            if(i == 0){
                num = checkRight(r, c);
                num += checkUp(r, c);
            }
            if(i == 1){
                num = checkRight(r, c);
                num += checkDown(r, c);
            }
            if(i == 2){
                num = checkLeft(r, c);
                num += checkUp(r, c);
            }
            if(i == 3){
                num = checkLeft(r, c);
                num += checkDown(r, c);
            }
            
            check(idx+1);
            
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    map[i][j] = temp[i][j];
                }
            }
        }
    }
    
    else if(map[r][c] == 4){
        int num;
        for(int i=0; i<4; i++){
            if(i == 0){
                num = checkRight(r, c);
                num += checkLeft(r, c);
                num += checkUp(r, c);
            }
            if(i == 1){
                num = checkRight(r, c);
                num += checkLeft(r, c);
                num += checkDown(r, c);
            }
            if(i == 2){
                num = checkRight(r, c);
                num += checkUp(r, c);
                num += checkDown(r, c);
            }
            if(i == 3){
                num = checkLeft(r, c);
                num += checkUp(r, c);
                num += checkDown(r, c);
            }
            
            check(idx+1);
            
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    map[i][j] = temp[i][j];
                }
            }
        }
    }
    else if(map[r][c] == 5){
        int num = checkRight(r, c);
        num += checkLeft(r, c);
        num += checkUp(r, c);
        num += checkDown(r, c);
        
        check(idx+1);
        
    }
    
}


int main () {
    
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] >=1 && map[i][j] <= 5){
                cctv[ccCnt][0] = i;
                cctv[ccCnt][1] = j;
                ccCnt++;
                
            }
        }
    }
    if(ccCnt > 0)
        check(0);
    
    else{
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == 0)
                    cnt++;
            }
        }
        minC = cnt;
    }
    
    printf("%d\n", minC);
    
}

