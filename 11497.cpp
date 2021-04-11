#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    int tc, n;
    int height[10000];
    int max = 0;
    int even_b, odd_b;  //이전꺼 저장
    int diff=0;
    
    scanf("%d", &tc);
    for(int i=0; i<tc; i++){
        max = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &height[i]);
        }
        
        sort(height, height+n);
        even_b = height[0];
        odd_b = height[0];
      
        
        for(int i=1; i<n-1; i++){
            if(i%2 == 1){   //홀수
                diff = height[i] - odd_b;
                odd_b = height[i];
                if(max< diff)
                    max = diff;
            }
            else{
                diff = height[i] - even_b;
                even_b = height[i];
                if(max< diff)
                    max = diff;
            }

        }
        
        if(max < height[n-1] - odd_b)
            max = height[n-1] - odd_b;
        
        if(max < height[n-1] - even_b)
            max = height[n-1] - even_b;
        
        printf("%d\n", max);
    }
}
