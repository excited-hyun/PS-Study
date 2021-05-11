#include <iostream>
#include <cstdio>

long long arr[101];

int main (void){
    int tc, n;
    
    scanf("%d", &tc);
    
    for(int i=0; i<tc; i++){
        scanf("%d", &n);
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 1;
        arr[4] = 2;
        arr[5] = 2;
     
        
        for(int j=6; j<n+1; j++){
            arr[j] = arr[j-1] + arr[j-5];
        }
        printf("%lld\n", arr[n]);
    }
}
