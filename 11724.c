
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_map(int ** map, int dot_num, int line_num);
void check(int **map, int dot_num, int n);

int visit[1000];

int main (void){
    int dot_num, line_num;
    int x, y;
    int **map;
    
    scanf("%d %d", &dot_num, &line_num);
  
    map = (int **)calloc(dot_num,sizeof(int *));
    for(int i=0; i<dot_num; i++){
        map[i] = (int*) calloc(dot_num,sizeof(int));
    }
    
    
    for(int i=0; i<line_num; i++){
        
        scanf("%d %d", &x, &y);
        map[x-1][y-1] = 1;
        map[y-1][x-1] = 1;
        
    }
    

    check_map(map, dot_num, line_num);
    
    
}

void check_map(int ** map, int dot_num, int line_num){
    int component = 0;
    
    for(int i=0; i<dot_num; i++){
        if(visit[i] != 1){
            component ++;
            visit[i] = 1;
            check(map, dot_num, i);
        }
    }
    printf("%d\n", component);
}

void check(int **map, int dot_num, int n){
    for(int i=0; i<dot_num; i++){
        if(visit[i]!= 1 && map[n][i] == 1){
            visit[i] = 1;
            check(map, dot_num, i);
        }
    }
}
