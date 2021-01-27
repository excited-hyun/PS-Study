#include <stdio.h>
#include <stdlib.h>

int space[20][20];
int visited[20][20];

int total = 0;
int ate = 0;
int body = 2;
int min_x=20, min_y = 20, min_cnt =400;

struct Node{
    int x;
    int y;
    int cnt;
    struct Node *next;
};

int x[4] = {-1, 0, 0, 1};
int y[4] = {0, -1, 1, 0};
void init_visit(struct Node* head, int X, int Y);
void search_map(struct Node* head, int n);

int main(void) {
    int n;
    int init_x = 0, init_y = 0;
    struct Node * head;
    struct Node * new_node;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &space[i][j]);
            if(space[i][j] == 9){
                init_x = i;
                init_y = j;
                space[i][j] = 0;
            }
        }
    }
    
    head = (struct Node*)malloc(1*sizeof(struct Node));
    new_node = (struct Node*)malloc(1*sizeof(struct Node));
    head->next = new_node;
    new_node -> x = init_x;
    new_node -> y = init_y;
    new_node -> cnt = 0;
    new_node -> next = NULL;
    
    search_map(head, n);
    printf("%d\n", total);
}

void search_map(struct Node* head, int n){
    struct Node *temp, *new, *use;
    int X, Y;
    int sw=0;
    int can=0;
    temp = head->next;
    use = temp;
    while(head -> next != NULL){
        //printf("다음!%d %d\n", use->x, use->y);
        
        temp = head->next;
        visited[temp->x][temp->y] = 1;
        if(temp == NULL)
            break;
   
        //printf("%d %d\n", temp->x, temp->y);
        for(int i=0; i<4; i++){
            
            X = temp->x + x[i];
            Y = temp->y + y[i];
            if(X < 0 || X >= n || Y <0 || Y >= n){
                continue;
            }
            if(space[X][Y] > body || visited[X][Y] ==1){
                continue;
            }
            
            if(space[X][Y]!=0 && space[X][Y] < body){
                temp->cnt = temp-> cnt +1;
                if(temp->cnt <= min_cnt){
                    min_cnt = temp->cnt;
                    if(X < min_x){
                        min_x = X;
                        min_y = Y;
                    }
                    else if(X == min_x){
                        if(Y<min_y)
                            min_y = Y;
                    }
                    can++;
                }
                continue;
                
            }
            //안먹고 이동
            visited[X][Y] = 1;
            
            new = (struct Node*)malloc(1*sizeof(struct Node));
            new->x = X;
            new->y = Y;
            new->cnt = temp-> cnt +1;
            new->next = NULL;

            use->next = new;
            use = use->next;
            
        }
        
        if((temp->next == NULL&& can != 0) || (temp->next != NULL && can != 0 && (temp->next)->cnt > min_cnt)){
            ate++;
            space[min_x][min_y] = 0;

        
        //printf("%d\n", temp->cnt);
            total += min_cnt;
            if(ate == body){
                ate=0;
                body++;
            }
        //head->next = NULL;
            init_visit(head, min_x, min_y);
        
            temp = head->next;
            use=temp;
            sw = 1;
            can = 0;
            
        }

        if(sw==1){
            sw=0;
            continue;
        }
        if(temp->next == NULL)
            break;
        head->next = temp->next;
        free(temp);
    }
}

void init_visit(struct Node* head, int X, int Y){
    
    struct Node * new_node;
    struct Node *temp;
    for(int i=0; i< 20; i++){
        for(int j=0; j<20; j++){
            visited[i][j] = 0;
        }
    }
    while(head->next != NULL){
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
    //printf("%d %d\n", X, Y);
    
    new_node = (struct Node*)malloc(1*sizeof(struct Node));
    head->next = new_node;
    new_node -> x = X;
    new_node -> y = Y;
    new_node -> cnt = 0;
    new_node -> next = NULL;
    min_x=20;
    min_y = 20;
    min_cnt =400;
}
