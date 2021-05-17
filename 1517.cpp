#include <iostream>
#include <cstdio>

using namespace std;


int arr[500001];
int temp[500001];

long long solve(int start, int end)
{
    if (start == end) return 0;
    int mid = (start + end) / 2;

    long long ans = solve(start, mid) + solve(mid + 1, end);

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid || j <= end)
    {
        if (i <= mid && (j > end || arr[i] <= arr[j]))
        {
            temp[k++] = arr[i++];
        }
        else
        {
            // 왼쪽 배열의 남아있는 원소들의 개수
            ans += (long long)(mid - i + 1);
            temp[k++] = arr[j++];
        }
    }

    for (int i = start; i <= end; i++) {
        arr[i] = temp[i - start];
    }
    return ans;
}
int main()
{
    int n;
    long long result;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

   
    result = solve(0, n - 1);

    printf("%lld\n", result);
}
