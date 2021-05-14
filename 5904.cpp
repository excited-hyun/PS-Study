#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

char s1[3] = {'m', 'o','o'};

void sol(int n, int k, int len){
    int new_len = len*2 + k+3;
    if(n<=3){
        printf("%c\n", s1[n-1]);
        exit(0);
    }
    if(new_len < n){
        sol(n, k+1, new_len);
    }
    else{
        if(n > len && n <= len+k+3){
            if(n-len != 1)
                printf("o\n");
            else
                printf("m\n");
            exit(0);
        }
        else{
            sol(n-(len+k+3), 1, 3);
        }
    }
}

int main(void){
    int n;
   
    scanf("%d", &n);
    
    sol(n, 1, 3);
    
}
