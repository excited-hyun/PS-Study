#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> sol;

int check(long long n){
    for(int i=2; i*i <= n; i++){
        if(n % i ==0)
            return 0;
    }
    return 1;
}

void dfs (int now, long long num){
    int flag;
    long long temp;
    
    if(now == n){
        sol.push_back(num);
        return;
    }
    
    for(int i=0; i<10; i++){
        temp = num * 10;
        temp +=i;
        flag = check(temp);
        if(flag == 0)
            continue;
        
        dfs(now+1, temp);
    }
}

int main (void){
    
    long long num;
    
    scanf("%d", &n);
    
    
    num = 2;
    dfs(1, num);
    num = 3;
    dfs(1, num);
    num = 5;
    dfs(1, num);
    num = 7;
    dfs(1, num);
    
    sort(sol.begin(), sol.end());
    
    for(int i=0; i<sol.size(); i++)
        printf("%lld\n", sol[i]);
}
