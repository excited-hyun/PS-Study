#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char input1[1000];
char input2[1000];

int lcs[1001][1001];

int Max(int a, int b) {
    if(a>b)
        return a;
    else
        return b;
}

int main(void){
    int len1, len2;
    scanf("%s", input1);
    scanf("%s", input2);
    
    len1 = strlen(input1);
    len2 = strlen(input2);
    for(int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            if(input1[i] == input2[j]){
                lcs[i+1][j+1] = lcs[i][j] + 1;
            }
            else{
                lcs[i+1][j+1] = Max(lcs[i][j+1], lcs[i+1][j]);
            }
        }
    }
    
    
    
    printf("%d\n", lcs[len1][len2]);
}
