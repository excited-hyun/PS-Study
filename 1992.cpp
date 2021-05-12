#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

char map[65][65];

void sol(int n, int x, int y){
    int div = n/2;
    int check_x, check_y;
    char check;
    int flag = 0;
    
    if(n==0)
        return;
        
    printf("(");
    
    for(int i=0; i<4; i++){//i값에 따라 왼위, 오위, 왼아래, 오아래
        if(i==0){
            check_x = x;
            check_y = y;
        }
        else if(i==1){
            check_x = x;
            check_y = y+div;
        }
        else if(i==2){
            
            check_x = x+div;
            check_y = y;
        }
        else if(i==3){
            check_x = x+div;
            check_y = y+div;
        }
        flag = 0;
        check = map[check_x][check_y];
        for(int j=0; j<div; j++){
            for(int k=0; k<div; k++){
                if(check!=map[check_x+j][check_y+k]){
                    sol(div, check_x, check_y);
                    flag = 1;
                    break;
                }
                    
            }
            if(flag == 1){
                break;
            }
        }
        if(flag == 0)
            printf("%c", check);
    }
    printf(")");
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", map[i]);
    }
    
    int flag = 0;
    char check = map[0][0];
    for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
            if(check!=map[j][k]){
                flag = 1;
                break;
            }
                
        }
        if(flag == 1){
            break;
        }
    }
    
    if(flag == 0)
        printf("%c", check);
    else
        sol(n, 0, 0);
    printf("\n");
}
