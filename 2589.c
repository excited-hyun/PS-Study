#include <stdio.h>
#include<stdlib.h>

struct Node{
    int x;
    int y;
    int cnt;
    struct Node *next;
};

char **map;
int **visit;

int search_map(struct Node* head, int n, int m);

int main(void){
    int n, m;
    int cnt = 0, max = 0;
    struct Node * head;
    struct Node * new_node;
    
    scanf("%d %d", &n, &m);
    map = (char**)malloc(n*sizeof(char*));
    visit = (int**)calloc(n, sizeof(int*));
    for(int i=0; i<n; i++){
        map[i] = (char*)malloc(m*sizeof(char));
        scanf("%s", map[i]);
        visit[i] = (int*)calloc(m, sizeof(int));
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 'W')
                continue;
            
            head = (struct Node*)malloc(1*sizeof(struct Node));
            new_node = (struct Node*)malloc(1*sizeof(struct Node));
            head->next = new_node;
            new_node -> x = i;
            new_node -> y = j;
            new_node -> cnt = 0;
            new_node -> next = NULL;
            
            cnt = search_map(head, n, m);
            
            if(cnt > max){
                max = cnt;
            }
            //printf("%d %d %d\n", i, j, cnt);
        }
    }
    printf("%d\n", max);
}

int search_map(struct Node* head, int n, int m){
    int max = 0;
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    int X, Y;
    struct Node *temp, *new, *use;
    temp = head;
    temp = temp->next;
    use = temp;
    visit[temp->x][temp->y] = 1;
    //printf("!!!!!!!!!%d %d\n", temp->x, temp->y);
    
    while(head -> next != NULL){
        //printf("다음!%d %d\n", use->x, use->y);
        
        temp = head->next;
        if(temp == NULL)
            break;
        //printf("%d %d\n", temp->x, temp->y);
        for(int i=0; i<4; i++){
            //printf("?%d %d\n", temp->x + x[i], temp->y + y[i]);
            X = temp->x + x[i];
            Y = temp->y + y[i];
            if(X < 0 || X >= n || Y <0 || Y >= m){
                continue;
            }
            if(visit[X][Y] == 1 || map[X][Y] == 'W'){
                continue;
            }
            
            visit[X][Y] = 1;
            new = (struct Node*)malloc(1*sizeof(struct Node));
            new->x = X;
            new->y = Y;
            new->cnt = temp->cnt + 1;
            new->next = NULL;
            //printf("%d %d %d\n", new->x, new->y, new->cnt);
            use->next = new;
            use = use->next;
            if(new->cnt > max)
                max = new->cnt;
            
        }

        if(temp->next == NULL)
            break;
        head->next = temp->next;
        free(temp);
        //dequeue(head);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visit[i][j] = 0;
        }
    }
    return max;
}


