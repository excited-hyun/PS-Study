#include <stdio.h>

int main (void){
    int a, b;
    int cnt= 0;
    scanf("%d %d", &a, &b);
    while(a<=b){
        if(b%10 == 1){
            b = b/10;
            cnt++;
        }
        else if (b%2 != 0){
            cnt = -1;
            break;
        }
        else{
            b = b/2;
            cnt++;
        }
        if (b == a){
            cnt++;
            break;
        }
        else if(b<a){
            cnt = -1;
            break;
        }
    }
    printf("%d\n", cnt);
}

