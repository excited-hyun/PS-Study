#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int use_seq[100];
bool will_use[100];
int tab[100];
int cnt;
int change;

int main(void){
    int n, k;
    int now;
    int off;
    bool found;
    bool already;
    
    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++){
        scanf("%d", &use_seq[i]);

    }
    for(int i=0; i<k; i++){
        now = use_seq[i];
        already = false;
        for(int j=0; j<n; j++){
            if(tab[j] == now){  //이미 꽂혀 있음
                already = true;
                break;
            }
            if(tab[j]==0){      //빈칸 있음
                tab[j] = now;
                already = true;
                break;
            }
        }
        if(already == true)
            continue;
        
        cnt = 0;
        found = false;
        
        for(int l=0; l<n; l++){
            will_use[l] = false;
        }
        
        for(int j=i+1; j<k; j++){
            if(found)
                break;
            for(int l=0; l<n; l++){
                if(cnt == n-1 && will_use[l] == false){ //꽂힌 거 중에 안쓰는거 찾음
                    off = l;
                    found = true;
                    break;
                }
                
                if(use_seq[j] == tab[l] && will_use[l] == false){
                    will_use[l] = true;
                    cnt++;
                    break;
                }
                else if(use_seq[j] == tab[l] && will_use[l] == true)
                    break;
            }
        }
        if(!found){
            for(int l=0; l<n; l++){
                if(will_use[l] == false)
                    off = l;
            }
        }
        tab[off] = now;
        change++;
        
    }
    printf("%d\n", change);
}
