#include <iostream>
#include <cstdio>

int count[100001];

int main (void){
    int n;
    int min;
    int temp;
    
    scanf("%d", &n);
    
    count[0] = 0;
    count[1] = 1;
    
    for(int i=2; i<n+1; i++){
        min = count[i-1] + 1;
        for(int j=2; j*j<=i; j++){
            
            temp = count[i-(j*j)] + 1;
            if(min > temp)
                min = temp;
        }
        
        count[i] = min;
       // printf("%d %d\n", i, count[i]);
    }
    printf("%d\n", count[n]);
}
