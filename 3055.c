#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    int y;
    int water; //물이면 1 아니면 0
    int cnt;
    struct Node *next;
};
char map[50][50];
int water[50][50];
int visit[50][50];
int move_cnt;
int fin_x, fin_y;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

void bfs(struct Node*head, int r, int c);

int main(void){
    int r, c;
    struct Node * head, *new, *temp;
    
    scanf("%d %d", &r, &c);
    
    for(int i=0; i<r; i++){
        
        scanf("%s", map[i]);
    }
    
    head = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    //물이 생길 곳으로 도치가 이동을 못하므로 물부터 큐에 넣어줌
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] == '*'){
                new = (struct Node *)malloc(sizeof(struct Node));
                new->x = i;
                new->y = j;
                new->water = 1;
                new->cnt = 0;
                new->next = NULL;
                temp->next = new;
                temp = temp->next;
                water[i][j] = 1;
            }
            if(map[i][j] == 'D'){
                fin_x = i;
                fin_y = j;
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] == 'S'){
                new = (struct Node *)malloc(sizeof(struct Node));
                new->x = i;
                new->y = j;
                new->water = 0;
                new->cnt = 0;
                new->next = NULL;
                temp->next = new;
                visit[i][j] = 1;
                break;
            }
        }
    }

    bfs(head, r, c);
    if(move_cnt==-1){
        printf("KAKTUS\n");
    }
    else{
        printf("%d\n", move_cnt);
    }
}
void bfs(struct Node*head, int r, int c){
    struct Node *temp, *use, *new;
    int X, Y;
    use = head->next;
    while(use->next != NULL){
        use = use->next;
    }
    
    while(head->next!=NULL){
        temp = head->next;
        for(int i=0; i<4; i++){
            X = temp->x+x[i];
            Y = temp->y+y[i];
            
            if(X<0 || X>=r || Y<0 || Y>=c)
                continue;
            
            if(temp->water == 1){
                if(map[X][Y] =='X' || map[X][Y] == 'D' || water[X][Y] == 1)
                    continue;
                water[X][Y] = 1;
                new = (struct Node *)malloc(sizeof(struct Node));
                new->x = X;
                new->y = Y;
                new->water = 1;
                new->next = NULL;
                use->next = new;
                use = use->next;
                
            }
            else{
                if(map[X][Y] == 'X' || water[X][Y] == 1 || visit[X][Y] ==1)
                    continue;
                visit[X][Y]=1;
                new = (struct Node *)malloc(sizeof(struct Node));
                new->x = X;
                new->y = Y;
                new->water = 0;
                new->cnt = temp->cnt+1;
                new->next = NULL;
                use->next = new;
                use = use->next;
                move_cnt = new->cnt;
                if(X == fin_x && Y==fin_y)
                    return;
                
            }
        }
        head->next = temp->next;
        free(temp);
    }
    move_cnt = -1;
    
}
