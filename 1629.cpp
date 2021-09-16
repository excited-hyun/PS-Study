#include <cstdio>

long long cal(long long a, long long b, long long c) {
    if(b == 1)
        return a%c;
    
    long long tmp = cal(a, b/2, c) % c;
    if(b %2 == 0)
        return tmp * tmp % c;
    else
        return tmp * tmp % c * a % c;
}

int main() {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    
    long long ans = cal(a, b, c);
    
    printf("%lld\n", ans);
}

