#include <stdio.h>
#include <stdlib.h>

char map[25][25];
int visit[25][25];
int house_cnt;
int house[625];
int space;

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

struct Node{
    int x;
    int y;
    struct Node *next;
};

void bfs(struct Node *head, int n);

int main(void){
    int n;
    struct Node *head, *new;
    int temp;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%s", map[i]);
    }

    head = (struct Node*)malloc(sizeof(struct Node));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j] == 1 || map[i][j] == '0')
                continue;
            visit[i][j] = 1;
            space = 1;
            
            new = (struct Node*)malloc(sizeof(struct Node));
            new->x = i;
            new->y = j;
            new->next = NULL;
            head->next = new;
            
            bfs(head, n);
                                       
        }
    }
    printf("%d\n", house_cnt);
    for(int i=0; i<house_cnt; i++){
        for(int j = 0; j<house_cnt -i- 1; j++){
            if(house[j] > house[j+1]){
                temp = house[j+1];
                house[j+1] = house[j];
                house[j] = temp;
            }
        }
    }
    for(int i=0; i<house_cnt; i++){
        printf("%d\n", house[i]);
    }
}

void bfs(struct Node *head, int n){
    struct Node *temp, *new, *use;
    int X, Y;
    
    use = head->next;
    
    while(head->next != NULL){
        
        temp = head->next;
        for(int i=0; i<4; i++){
            X = temp->x + x[i];
            Y = temp->y + y[i];
            
            if( X<0 || X>=n || Y<0 || Y>=n)
                continue;
            
            if(visit[X][Y] == 1 || map[X][Y] == '0')
                continue;
            
            visit[X][Y] = 1;
            new = (struct Node*)malloc(sizeof(struct Node));
            new->x = X;
            new->y = Y;
            new->next = NULL;
            use->next = new;
            use = use->next;
            space++;
        }
        
        head->next = temp->next;
        free(temp);
    }
    house[house_cnt] = space;
    house_cnt++;
}
