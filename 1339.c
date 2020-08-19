
#include <stdio.h>
#include <stdlib.h>

int main (void){
    int n, i, j, temp;
    char word[10][10];
    int len[10];
    int result = 0;
    int alpa[26] = {0};
    int num = 9, use = 1;
    scanf("%d", &n);
    getchar();
    
    for(i=0; i<n; i++){
        j=0;
        scanf("%c", &word[i][j]);
        
        while(word[i][j] != '\n'){
            j++;
            scanf("%c", &word[i][j]);
            
        }
        len[i] = j;
    }
    
    for(i=0; i<n; i++){
        use = 1;
        for(j=len[i]-1; j>=0; j--){
            alpa[(word[i][j]-65)] += use;
            use *= 10;
        }
        
    }

    for(i=0; i<26-1; i++){
        for(j=0; j<26-(i+1); j++){
            if(alpa[j]<alpa[j+1]){
                temp = alpa[j+1];
                alpa[j+1] = alpa[j];
                alpa[j] = temp;
            }
        }
    }

    num=9;
    result = 0;
    
    for(i=0; i<26; i++){
        if(alpa[i] !=0 ){
            result += num * alpa[i];
            num--;
        }
    }
    printf("%d\n", result);
}
