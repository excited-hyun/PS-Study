#include <stdio.h>
#include<stdlib.h>

int ** visit;
char **map;
struct Node{
    int x;
    int y;
    int cnt;
    struct Node *next;
};

struct Node* find_map(struct Node* head, int fin_x, int fin_y);
void dequeue(struct Node *head);

int main(void){

    int size_x, size_y;
    struct Node *head;
    struct Node *new;
    struct Node *sw;
    scanf("%d %d", &size_x, &size_y);
    
    map = (char**)malloc(sizeof(char*)*size_x);
    visit = (int**)calloc(size_x, sizeof(int*));
    for(int i=0; i<size_x; i++){
        map[i] = (char*)malloc(size_y*sizeof(char));
        visit[i] = (int*)calloc(size_y, sizeof(int));
    }
    
    for(int i=0; i<size_x; i++){
        scanf("%s", map[i]);
    }
    head = (struct Node*)malloc(sizeof(struct Node) *1);
    new = (struct Node*)malloc(sizeof(struct Node) *1);
    head->next = new;
    new -> next = NULL;
    new->x = 0;
    new->y = 0;
    new->cnt = 1;
    visit[0][0] = 1;
    
    sw =NULL;
    while(sw == NULL){
        sw = find_map(head, size_x-1, size_y-1);
    }
    printf("%d\n", sw->cnt);
    
}

struct Node* find_map(struct Node* head, int fin_x, int fin_y)
{
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    
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
    for(int i=0; i<4; i++){
        if(check->x + x[i] < 0 || check->x + x[i] > fin_x || check->y + y[i] <0 || check->y + y[i] > fin_y){
            continue;
        }
        if(visit[check->x + x[i]][check->y + y[i]] == 0 && map[check->x + x[i]][check->y + y[i]] == '1'){
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
