#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int l, c;
int alpha[26];

char possible[16];
char result[16];
vector<string> ans;

void dfs(int cnt, int con, int vow, int idx){
    if(cnt == c){
        if (con >=1 && vow>=2){
            result[c] = '\0';
            ans.push_back(result);
        }
    }
    for(int i=idx+1; i<l; i++){
        if(alpha[possible[i]-'a'])
            continue;
        result[cnt] = possible[i];
        alpha[possible[i]-'a'] = 1;
        
        if(possible[i] == 'a'|| possible[i] == 'e'||possible[i] == 'i' ||possible[i] ==  'o' || possible[i] == 'u')
            dfs(cnt+1, con+1, vow, i);
        else
            dfs(cnt+1, con, vow+1, i);
        alpha[possible[i]-'a'] = 0;
    }
}

int main (void){
    
    scanf("%d %d", &c, &l);
    for(int i=0; i<l; i++){
        getchar();
        scanf("%c", &possible[i]);
    }
    
    sort(possible, possible+l);
    
    for(int i=0; i<l; i++){
        result[0] = possible[i];
        alpha[possible[i]-'a'] = 1;
        if(possible[i] == 'a'|| possible[i] == 'e'||possible[i] == 'i' ||possible[i] ==  'o' || possible[i] == 'u')
            dfs(1, 1, 0, i);
        else
            dfs(1, 0, 1, i);
        alpha[possible[i]-'a'] = 0;
    }
    
    sort(ans.begin(), ans.end());
    
    for(int i=0; i<ans.size(); i++)
        printf("%s\n", ans[i].c_str());
}
