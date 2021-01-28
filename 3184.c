#include <stdio.h>
#include <stdlib.h>

char map[250][250];
int visited[250][250];
int wolf=0;
int sheep=0;

int total_w=0;
int total_s=0;

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

struct Node {
    int x;
    int y;
    struct Node* next;
};

void bfs(struct Node * head, int r, int c);

int main(void){
    
    int r, c;
    struct Node * head;
    struct Node * new;
    scanf("%d %d", &r, &c);
    
    for (int i=0; i< r; i++){
        for(int j=0; j<c; j++){
            scanf("%c", &map[i][j]);
        }
        getchar();
    }
    
    head = (struct Node*) malloc(sizeof(struct Node));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(visited[i][j] == 1)
                continue;
            new = (struct Node*) malloc(sizeof(struct Node));
            new->x = i;
            new->y = j;
            new->next = NULL;
            head->next = new;
            bfs(head, r, c);
            wolf = 0;
            sheep = 0;
        }
    }
    printf("%d %d\n", total_s, total_w);
}

void bfs(struct Node * head, int r, int c){
    struct Node* temp, *new, *use;
    int X, Y;
    temp = head->next;
    use = temp;
    while(head->next != NULL){
        temp = head->next;
        for(int i=0; i<4; i++){
            X = temp->x + x[i];
            Y = temp->y + y[i];
            
            if( X< 0 || X>=r || Y<0 || Y>=c)
                continue;
            if(visited[X][Y] == 1 || map[X][Y] == '#')
                continue;
            
            visited[X][Y] = 1;
            if(map[X][Y] == 'v'){   //늑대
                wolf++;
            }
            if(map[X][Y] == 'o'){   //양
                sheep++;
            }
            new = (struct Node*) malloc(sizeof(struct Node));
            new->x = X;
            new->y = Y;
            new->next = NULL;
            use->next = new;
            use = use->next;
        }
        head->next = temp->next;
        free(temp);
    }
    if(sheep > wolf)
        total_s += sheep;
    else
        total_w += wolf;
}
