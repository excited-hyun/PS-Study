#include <iostream>
#include <cstdio>

int count[15];

int main(void){
    int t, n;
    
    count[1] = 1;
    count[2] = 2;
    count[3] = 4;
    
    scanf("%d", &t);
    
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        if(n == 1 || n==2 || n==3){
            printf("%d\n", count[n]);
            continue;
        }
        else{
            for(int j=4; j<n+1; j++){
                count[j] = count[j-1] + count[j-2] + count[j-3];
            }
        }
        printf("%d\n", count[n]);
    }
}
