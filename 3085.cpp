#include <iostream>
#include <cstdio>

char map[51][51];

int X[2] = {1, 0};
int Y[2] = {0, 1};

int find_candy(int n){
    int cnt= 1;
    int max_cnt = 1;
    
    for(int i=0; i<n; i++){
        cnt = 1;
        for(int j=0; j<n-1; j++){
            if(map[i][j] == map[i][j+1])
                cnt++;
            else
                cnt = 1;
            
            if(cnt > max_cnt)
                max_cnt = cnt;
        }
        
    }
    
    for(int j=0; j<n; j++){
        cnt = 1;
        for(int i=0; i<n-1; i++){
            if(map[i][j] == map[i+1][j])
                cnt++;
            else
                cnt = 1;
            
            if(cnt > max_cnt)
                max_cnt = cnt;
        }
        
    }
    
    return max_cnt;
}

int main (void) {
    int n;
    int c_x, c_y;
    int max_candy = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%s", map[i]);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<2; k++){
                c_x = i+X[k];
                c_y = j+Y[k];
                if(c_x >= n || c_y >= n)
                    continue;
                
                if(map[i][j] != map[c_x][c_y]){
                    int temp = map[i][j];
                    map[i][j] = map[c_x][c_y];
                    map[c_x][c_y] = temp;
                    
                    int cnt = find_candy(n);
                    if(cnt > max_candy)
                        max_candy = cnt;
                    
                    temp = map[i][j];
                    map[i][j] = map[c_x][c_y];
                    map[c_x][c_y] = temp;
                }
            }
        }
    }
    
    printf("%d\n", max_candy);
}
