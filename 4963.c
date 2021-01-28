#include <stdio.h>
#include <stdlib.h>

int map[50][50];
int visited[50][50];
int land_cnt;

int x[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int y[8] = {0, 0, 1, -1, 1, -1, 1, -1};

struct Node{
    int x;
    int y;
    struct Node * next;
    
};

void bfs(struct Node* head, int w, int h);

int main(void){
    int w, h;
    struct Node * head, *new;
    
    while(1)
    {
        scanf("%d %d", &w, &h);
        
        if (w == 0 && h == 0)
            break;
        
        land_cnt = 0;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d", &map[i][j]);
                visited[i][j] = 0;
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(visited[i][j] == 1 || map[i][j] == 0)
                    continue;
                visited[i][j] = 1;
                head = (struct Node*)malloc(sizeof(struct Node));
                new = (struct Node*)malloc(sizeof(struct Node));
                new->x = i;
                new->y = j;
                new->next = NULL;
                head->next = new;
                
                bfs(head, w, h);
            }
        }
        
        printf("%d\n", land_cnt);
        
    }
}

void bfs(struct Node *head, int w, int h){
    struct Node *temp, *new, *use;
    int X, Y;
    
    use = head->next;
    
    while(head->next != NULL){
        temp = head->next;
        
        for(int i=0; i<8; i++){
            X = temp->x + x[i];
            Y = temp->y + y[i];
            
            if( X < 0 || X >= h || Y<0 || Y >= w ){
                continue;
            }
            if(visited[X][Y] == 1 || map[X][Y] == 0){
                continue;
            }
            
            visited[X][Y] = 1;
            new = (struct Node*)malloc(sizeof(struct Node));
            new->x = X;
            new->y = Y;
            new->next = NULL;
            use->next = new;
            use = use-> next;
        }
        
        head->next = temp->next;
        free(temp);
    }
    land_cnt++;
}
