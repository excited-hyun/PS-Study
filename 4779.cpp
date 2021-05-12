#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

void sol(int n){
    if(n==0){
        printf("-");
        return ;
    }
    
    sol(n-1);
    
    for(int i=0; i<pow(3, n-1); i++)
        printf(" ");
    
    sol(n-1);
    
}

int main (void){
    int n;
    while (scanf("%d", &n) != EOF){
        sol(n);
        printf("\n");
    }
}
