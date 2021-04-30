#include <iostream>
#include <cstdio>

int map[2][100000];
int result[3][100000];

int main (void){
    int t, n;
    int no, up, down;
    int max_no, max_up, max_down;
    int max_sum=0;
    
    scanf("%d", &t);
    
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        for(int j=0; j<n; j++){
            scanf("%d", &map[0][j]);
        }
        for(int j=0; j<n; j++){
            scanf("%d", &map[1][j]);
        }
        result[0][0] = map[0][0];   //위
        result[1][0] = map[1][0];   //아래
        result[2][0] = 0;           //사용X
        
        for(int j=0; j<n-1; j++){
            for(int k=0; k<3; k++){
                if(k == 0){     //이전에 위 사용
                    max_down = result[k][j] + map[1][j+1];
                    max_no = result[k][j];
                }
                
                else if(k==1){  //이전에 아래 사용
                    max_up = result[k][j] + map[0][j+1];
                    no = result[k][j];
                    if(no > max_no)
                        max_no = no;
                }
                
                else{           //이전에 사용X
                    up = result[k][j] + map[0][j+1];;
                    down = result[k][j] + map[1][j+1];
                    no = result[k][j];
                   
                    if(up > max_up)
                        max_up = up;
                    if(down > max_down)
                        max_down = down;
                    if(no > max_no)
                        max_no = no;
                }
            }
            result[0][j+1] = max_up;
            result[1][j+1] = max_down;
            result[2][j+1] = max_no;
           // printf("%d %d %d\n", result[0][j+1], result[1][j+1], result[2][j+1]);
        }
        
        max_sum = result[0][n-1];
        for(int k=1; k<3; k++){
            if(max_sum < result[k][n-1])
                max_sum = result[k][n-1];
        }
        
        printf("%d\n", max_sum);
        
    }
}
