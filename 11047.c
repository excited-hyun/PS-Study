
#include <stdio.h>
#include <stdlib.h>

int main (void){
    int n, k;
    int *coin;
    int cnt = 0;
    scanf("%d %d", &n, &k);
    coin = (int*)malloc(sizeof(int)*n);
    
    for (int i=0; i<n; i++){
        scanf("%d", &coin[i]);
    }
    for(int i= n-1; i>=0; i--){
        while (k >= coin[i]){
            k -= coin[i];
            cnt++;
        }
    }
    printf("%d\n",cnt);
}

