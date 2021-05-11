#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

char pw[5001];
int can[5001][2];

int main (void){
    int len;
    int total;
    
    scanf("%s", pw);
    
    if(pw[0] == '0'){
        printf("0\n");
        return 0;
    }
    
    can[0][0] = 1;
    can[0][1] = 0;
    len = strlen(pw);
    
    for(int i=1; i<len; i++){
        //printf("%d %d\n", can[i-1][0], can[i-1][1]);
        if(pw[i] == '0'){
            if(pw[i-1] == '1' || pw[i-1] == '2'){
                can[i][0] = 0;
                can[i][1] = can[i-1][0]%1000000;
                continue;
            }
            else{
                printf("0\n");
                return 0;
            }
                
        }
        else if(pw[i-1] == '1' && pw[i] >= '0' && pw[i] <= '9'){
            can[i][1] = can[i-1][0]%1000000;
        }
        else if(pw[i-1] == '2' && pw[i] >= '0' && pw[i] <= '6'){
            can[i][1] = can[i-1][0]%1000000;
        }
        can[i][0] = (can[i-1][0] + can[i-1][1])%1000000;
    }
    
    total = (can[len-1][0] + can[len-1][1])%1000000;
    printf("%d\n", total);
}
