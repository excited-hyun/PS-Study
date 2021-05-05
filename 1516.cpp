#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int min_t[501];
int dp[501];
vector<vector<int>> map;

int dfs(int n, int i);

int main (void){
    int n;
    int a;
    int result;
    scanf("%d", &n);
    map.resize(n+1);
    for(int i=1; i<n+1; i++){
        scanf("%d", &min_t[i]);

        while(1){
            scanf("%d", &a);
            if(a==-1)
                break;
            map[i].push_back(a);
        }
    }
    
    for(int i=1; i<n+1; i++){
        result = dfs(n, i);
        printf("%d\n", result);
    }
}

int dfs(int n, int i){
    int temp = 0;
    if (dp[i] != 0)
        return dp[i];
    if(map[i].size() == 0)
        return min_t[i];
    
    for(int j=0; j<map[i].size(); j++){
        temp = max(temp, dfs(n, map[i][j]));
    }
    dp[i] = temp + min_t[i];
    return dp[i];
}
