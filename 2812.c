
#include <stdio.h>
#include <stdlib.h>

int main (void){
    int n, k, i, j, l;
    char num[500000];
    int max[500000];
    int max_i;
    scanf("%d %d", &n, &k);
    getchar();
    for(int i=0; i<n; i++){
        scanf("%c", &num[i]);
    }
    j = k;
    l=0;
    max_i = -1;
    for(i=0; i<n; i++){
        while (j > 0 && l > 0 && max[l - 1] < num[i]-48) {
            l--;
            j--;
        }
        max[l] = num[i]-48;
        l++;
    }

    for(i=0; i<n-k; i++){
        printf("%d",max[i]);
    }
    printf("\n");
}


