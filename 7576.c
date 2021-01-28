#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    int y;
    int day;
    struct Node *next;
};

int t_box[1000][1000];
int visit[1000][1000];
int tot_day;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

void bfs(struct Node* head, int m, int n);

int main(void){
    int m,n;
    struct Node *head, *new, *temp;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    
    
    scanf("%d %d", &n ,&m);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &t_box[i][j]);
            if(t_box[i][j] == 1){
                new = (struct Node*)malloc(sizeof(struct Node));
                new->x = i;
                new->y = j;
                new->day = 0;
                new->next = NULL;
                temp->next = new;
                temp = temp->next;
                visit[i][j] = 1;
                
            }
            
        }
    }
    
    bfs(head, m,n);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(t_box[i][j] == 0 && visit[i][j] == 0)
                tot_day = -1;
        }
    }
    printf("%d\n", tot_day);
}

void bfs(struct Node* head, int m, int n){
    struct Node * temp, *new, *use;
    int X, Y;
    use = head->next;
    while(use->next != NULL){
        use = use->next;
    }
    
    while(head->next !=NULL){
        temp = head->next;
        for(int i=0; i<4; i++){
            X =temp->x + x[i];
            Y= temp->y + y[i];
            if(X<0 || X>=m || Y<0 || Y>= n)
                continue;
            if(visit[X][Y] == 1 || t_box[X][Y] == -1)
                continue;
            visit[X][Y] = 1;
            new = (struct Node*)malloc(sizeof(struct Node));
            new->x = X;
            new->y = Y;
            new->day = temp->day +1;
            new->next = NULL;
            use->next = new;
            use = use->next;
            tot_day = new->day;
            
        }
        head->next = temp->next;
        free(temp);
    }
    
}
