#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void)
{
    int N, k;
    
    scanf("%d", &N);
    scanf("%d", &k);

    int low = 1;
    int high = k;
    int mid;
    
    int sol = 0;

    while(high>=low)
    {
        mid = (low + high) / 2;

        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            cnt += min(N, mid / i);
        }

        if (cnt >= k)
        {
            sol = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("%d\n", sol);

    return 0;
}
