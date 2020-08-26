
#include <stdio.h>
#include <stdlib.h>

int ** visit;
struct Node{
    int x;
    int y;
    int cnt;
    struct Node *next;
};

struct Node * move_board(struct Node *head, int fin_x, int fin_y, int size);
void dequeue(struct Node *head);

int main(void){
    int n, size, init_x, init_y, fin_x, fin_y;
    struct Node *head;
    struct Node *new_node;
    struct Node *sw;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &size);
        scanf("%d %d", &init_x, &init_y);
        scanf("%d %d", &fin_x, &fin_y);
        
        visit = (int**)calloc(size, sizeof(int*));
        
        for(int j=0; j<size; j++){
            visit[j] = (int*)calloc(size, sizeof(int));
        }
        
        head = (struct Node*)malloc(sizeof(struct Node)*1);
        new_node = (struct Node*)malloc(sizeof(struct Node)*1);
        head ->next = new_node;
        new_node -> x = init_x;
        new_node -> y = init_y;
        new_node->cnt =0;
        new_node -> next = NULL;
        sw = NULL;
        visit[init_x][init_y]=1;
        
        while(1){
            if(sw!=NULL){
                break;
            }
            sw = move_board(head, fin_x, fin_y, size);
        }
        printf("%d\n", sw->cnt);
    }
}

struct Node * move_board(struct Node *head, int fin_x, int fin_y, int size){
    int x[8] = {1, 2, 1, 2,-1,-2,-1,-2};
    int y[8] = {2, 1,-2,-1, 2, 1,-2,-1};
    struct Node *temp, *check, *new_node;
    temp = head;
    temp = temp->next;
    check = head;
    check = check->next;

    if(check->x == fin_x && check->y == fin_y){
        return check;
    }
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    for(int i=0; i<8; i++){
        if(check->x + x[i] < 0 || check->x + x[i] >= size || check->y + y[i] <0 || check->y + y[i] >= size){
            continue;
        }
        if(visit[check->x + x[i]][check->y + y[i]] == 0){

            new_node = (struct Node*)malloc(sizeof(struct Node)*1);
            temp->next = new_node;
            new_node -> next = NULL;
            new_node -> x = check->x + x[i];
            new_node -> y = check->y + y[i];
            new_node -> cnt = check-> cnt + 1;
            visit[new_node->x][new_node->y] = 1;
            if(new_node->x == fin_x && new_node->y == fin_y){
                 return new_node;
            }
            //printf("%d %d %d\n", new_node->x, new_node->y, new_node->cnt);
            temp = temp->next;
        }
        
    }
    dequeue(head);
    
    return NULL;
}

void dequeue(struct Node *head)
{
    struct Node *del;
    if (head->next==NULL)//큐가 비었을 때
    {
        return ;
    }
    
    del = head->next;

    head->next = del->next;
    free(del);
}
