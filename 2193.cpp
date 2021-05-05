#include <iostream>
#include <cstdio>

using namespace std;

long long num[100][2];

int main (void) {
    int n;
    long long result;
    
    scanf("%d", &n);
    num[1][0] = 0;
    num[1][1] = 1;
    for(int i=2; i<n+1; i++){
        num[i][0] = num[i-1][1] + num[i-1][0];
        num[i][1] = num[i-1][0];
        
    }
    result = num[n][0] + num[n][1];
    
    printf("%lld\n", result);
}
