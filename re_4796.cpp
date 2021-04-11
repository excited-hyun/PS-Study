#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main (void){
    int L, P, V;
    int max_day;
    int left_day;
    int i=0;
    
    while(1){
    
        i++;
        scanf("%d %d %d", &L, &P, &V);
    
        if(L==0 && P==0 && V==0)
            break;
    
        max_day = (V/P)*L;
    
        left_day = V - ((V/P)*P);
        if(left_day > L)
            max_day += L;
        else
            max_day += left_day;
    
        printf("Case %d: %d\n", i, max_day);
    }
}
