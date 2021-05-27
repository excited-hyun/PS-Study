#include <iostream>
#include <cstdio>

int arr[21];
int cnt;
int n, s;

void adding (int cur_num, int cur_idx, int add_cnt){
    if(cur_num==s && add_cnt!=0){
        cnt++;
        add_cnt=0;
    }
    cur_idx++;
    if(cur_idx == n)
        return;
    adding(cur_num, cur_idx, add_cnt); //현재 idx의 수 안 더함
    adding(cur_num+arr[cur_idx], cur_idx, add_cnt+1); //현재 idx의 수 더함
    
}

int main (void){
    
    scanf("%d %d", &n, &s);
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    adding(0, 0, 0);    //첫번째 수 안 더함
    
    adding(arr[0], 0, 1);   //첫번째 수 더함
    
    printf("%d\n", cnt);
}
