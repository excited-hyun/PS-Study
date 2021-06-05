#include <iostream>
#include <cstdio>
#include <cstring>

char voca[50][20];
int teach[26];
int n, k;
int max_read = 0;

void check_read(){
    int cnt=0;
    int flag;
    
    for(int i=0; i<n; i++){
        flag = 1;
        for(int j=0; j<strlen(voca[i]); j++){
            if(teach[voca[i][j]-'a'] == 0){
                
                flag = 0;
                break;
            }
        }
        
        if(flag)
            cnt++;
    }
    if(cnt > max_read)
        max_read = cnt;
}

void dfs(int cnt, int idx){
    
    if(cnt == k){
        check_read();
        return;
    }
    
    for(int i=idx+1; i<26; i++){
        if(teach[i])
            continue;
        
        teach[i] = 1;
        dfs(cnt+1, i);
        teach[i] = 0;
    }
}

int main (void){

    scanf("%d %d", &n, &k);
    
    for(int i=0; i<n; i++)
        scanf("%s", voca[i]);
    if(k<5){
        printf("0\n");
        return 0;
    }
    else if(k == 26){
        printf("%d\n", n);
        return 0;
    }
    
    teach['a'-'a'] = 1;
    teach['c' - 'a'] = 1;
    teach['i' - 'a'] = 1;
    teach['n' - 'a'] = 1;
    teach['t' - 'a'] = 1;
    
    if(k==5){
        check_read();
        printf("%d\n", max_read);
        return 0;
    }
    
    for(int i=0; i<26; i++){
        if(teach[i])
            continue;
        teach[i] = 1;
        dfs(6, i);
        teach[i] = 0;
    }
    printf("%d\n", max_read);
}
