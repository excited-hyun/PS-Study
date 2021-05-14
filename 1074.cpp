#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n, r, c;
int result = 0;

int X[4] = {0, 0, 1, 1};
int Y[4] = {0, 1, 0, 1};

void sol (int now_n, int now_r, int now_c){
    if (now_n==1){
        if(now_r<=r && now_r+1 >= r && now_c <=c && now_c+1 >= c){
            for(int i=0; i<4; i++){
                if(r == now_r + X[i] && c== now_c+Y[i]){
                    printf("%d\n", result);
                    exit(0);
                }
                result++;
            }
        }
        else
            result+=4;
    }
    else{
        if(now_r<=r && now_c<=c && now_r+pow(2, now_n)>=r && now_c+pow(2, now_n)>=c){
            sol(now_n-1, now_r, now_c);
            sol(now_n-1, now_r, now_c+pow(2, now_n-1));
            sol(now_n-1, now_r+pow(2, now_n-1), now_c);
            sol(now_n-1, now_r+pow(2, now_n-1), now_c+pow(2, now_n-1));
        }
        else
            result+=pow(2, now_n)*pow(2, now_n);
    }
}

int main (void){
    
    scanf("%d %d %d", &n, &r, &c);
    
    sol(n, 0, 0);
}
