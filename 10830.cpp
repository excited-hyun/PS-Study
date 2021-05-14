#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;
int mat[6][6];

int** sol(int n, long long k){
    int **use;
    int **temp;
    int **result;
    long long new_k = k/2;
    
    result = (int **)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
        result[i] = (int *)calloc(n, sizeof(int));
    
    temp = (int **)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
        temp[i] = (int *)calloc(n, sizeof(int));
    
    if(k==2){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k< n; k++)
                    result[i][j] += mat[i][k]*mat[k][j];
                result[i][j] = result[i][j]%1000;
            }
        }
        return result;
    }
    
    else if(k==3){
        use = sol(n, 2);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k< n; k++)
                    result[i][j] += use[i][k]*mat[k][j];
                temp[i][j] = result[i][j]%1000;
            }
        }
    }
    else{
        use = sol(n, new_k);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k< n; k++)
                    result[i][j] += use[i][k]*use[k][j];
                result[i][j] = result[i][j]%1000;
            }
        }
        
        if(k%2){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    for(int k=0; k< n; k++)
                        temp[i][j] += result[i][k]*mat[k][j];
                    temp[i][j] = temp[i][j]%1000;
                }
            }
        }
        
    }
    
    if(k%2 == 0){
        for(int i=0; i<n; i++){
            free(use[i]);
            free(temp[i]);
        }
        free(use);
        free(temp);
        
        return result;
    }
    else{
        for(int i=0; i<n; i++){
            free(use[i]);
            free(result[i]);
        }
        free(use);
        free(result);
        return temp;
    }
}

int main(void){
    int n;
    long long b;
    int **result;
    
    scanf("%d %lld", &n, &b);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    if(b==1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%d ", mat[i][j]%1000);
            }
            printf("\n");
        }
        return 0;
    }
    
    result = sol(n, b);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
