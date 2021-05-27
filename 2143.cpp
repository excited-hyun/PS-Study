#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e8;

int a[1000], b[1000];
vector<int> sum_a, sum_b;

int main()
{
    
    int t;
    int n, m;
    int sum;
    
    scanf("%d", &t);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    

    for (int i = 0; i < n; i++) {
        sum = a[i];
        sum_a.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            sum_a.push_back(sum);
        }
    }
    

    for (int i = 0; i < m; i++) {
        sum = b[i];
        sum_b.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += b[j];
            sum_b.push_back(sum);
        }
    }
    
    sort(sum_b.begin(), sum_b.end());

    long long ans = 0;
    for (int i=0; i<sum_a.size(); i++)
    {
        int diff = t - sum_a[i];
        int ub = upper_bound(sum_b.begin(), sum_b.end(), diff) - sum_b.begin();
        int lb = lower_bound(sum_b.begin(), sum_b.end(), diff) - sum_b.begin();
        ans += (ub - lb);
    }
    
    printf("%lld\n", ans);

    return 0;
}
