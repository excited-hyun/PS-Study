#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<vector<int>> way;
int cost[1001];
int visited[1001];
int sw;

void dfs(int now, int money){
    if(sw == 1)
        return;
    
    // n번째 방 도착
    if(now == n) {
        sw = 1;
        return;
    }
    
    for(int i=0; i<way[now].size(); i++) {
        int next = way[now][i];
        
        if(visited[next] == 1)
            continue;
        
        // L
        if(cost[next] > 0 ) {
            if(cost[next] > money)
                money = cost[next];
        }
        // T or E
        else
            money += cost[next];
        
        //돈 부족해서 못감
        if(money < 0)
            return;
        
        visited[next] = 1;
        dfs(next, money);
        visited[next] = 0;
    }
}

int main () {
    
    while(1){
        scanf("%d", &n);
        if(n == 0)
            break;
       
        way.resize(n+1);
        sw = 0;
        for(int i=1; i<=n; i++){
            char info;
            int c;
            getchar();
            scanf("%c %d", &info, &c);
            while(1) {
                int next;
                scanf("%d", &next);
                if(next == 0)
                    break;
                way[i].push_back(next);
            }
            if(info == 'T')
                cost[i] = -c;
            else
                cost[i] = c;
        }
        
        if(cost[1] >= 0) {
            visited[1] = 1;
            dfs(1, cost[1]);
        }
        
        if(sw == 1)
            printf("Yes\n");
        else
            printf("No\n");
        
        way.clear();
        for(int i=0; i<=n; i++){
            cost[i] = 0;
            visited[i] = 0;
        }
        
    }
}
