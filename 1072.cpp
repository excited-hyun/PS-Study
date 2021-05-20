#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main (void) {
    long long x, y;
    long long z, result, re;

    scanf("%lld %lld", &x, &y);
    
    z = (100*y)/x;
    if(z >= 99){
        printf("-1\n");
        return 0;
    }
    
    re = (100*y-z*x-x) % (z-99);
    result = (100*y-z*x-x) / (z-99);
    if(re == 0){
        printf("%lld\n", result);
    }
    else{
        printf("%lld\n", result+1);
    }
    
}
