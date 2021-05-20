#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> memo_1;
int n;
int m;

void sol(int find){
    int low = 0;
    int high = n-1;
    int mid;
    
    while(high >= low){
        mid = (low + high) / 2;
        
        if(find > memo_1[mid])
            low = mid+1;
        else if(find < memo_1[mid])
            high = mid-1;
        else{
            printf("1\n");
            return ;
        }
    }
    printf("0\n");
}

int main(void){
    int tc;
    int num;
    
    scanf("%d", &tc);
    
    for(int i=0; i<tc; i++){
        scanf("%d", &n);
        for(int j=0; j<n; j++){
            scanf("%d", &num);
            memo_1.push_back(num);
        }
        sort(memo_1.begin(), memo_1.end());
        
        scanf("%d", &m);
        for(int j=0; j<m; j++){
            scanf("%d", &num);
            sol(num);
            
        }
        memo_1.clear();
    }
}
