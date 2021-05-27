#include <iostream>
#include <cstdio>

int printed[10];
int arr[10];

void printing(int n, int cnt){
    if(n==cnt){
        for(int i=0; i<n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return ;
    }
    for(int i=1; i<=n; i++){
        if(printed[i] == 1)
            continue;
        arr[cnt] = i;
        printed[i] = 1;
        cnt++;
        printing(n, cnt);
        printed[i] = 0;
        cnt--;
    }
}

int main (void){
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        arr[0]=i;
        printed[i] = 1;
        printing(n, 1);
        printed[i] = 0;
        
    }
}
