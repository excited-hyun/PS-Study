#include <iostream>
#include <cstdio>

int map[500][500];
int result[500][500];

int main(void){
    int n;
    int temp1, temp2;
    int max = 0;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            scanf("%d", &map[i][j]);
        }
    }
    result[0][0] = map[0][0];
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(j==0)
                result[i][j] = result[i-1][j] + map[i][j];
            else if(j == i)
                result[i][j] = result[i-1][j-1]+map[i][j];
            else{
                temp1 = result[i-1][j-1] + map[i][j];
                temp2 = result[i-1][j] + map[i][j];
                if(temp1 > temp2)
                    result[i][j] = temp1;
                else
                    result[i][j] = temp2;
            }
        }
    }
    max = result[n-1][0];
    for(int i=1; i<n; i++){
        if(max < result[n-1][i])
            max = result[n-1][i];
    }
    printf("%d\n", max);
}
