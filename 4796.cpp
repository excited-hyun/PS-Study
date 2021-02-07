#include <iostream>
#include <cstdio>

int main(void){
    int l, p, v;
    int case_n = 1;
    int use = 0;
    
    while(1){
        scanf("%d %d %d", &l, &p, &v);
        if(l == 0 && p == 0 && v==0)
            break;
        if(l > v%p)
            use = v%p + v/p*l;
        else
            use = use = l + v/p*l;
        printf("Case %d: %d\n", case_n, use);
        case_n++;
        
    }
}
