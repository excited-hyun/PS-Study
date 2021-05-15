#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int in[100001];         //inorder저장
int post[100001];       //postorder저장
int in_temp[100001];    //inorder의 root 쉽게 찾기 위해 사용, 숫자에 대한 위치 저장

void sol(int in_s, int in_f, int post_s, int post_f){
    if(in_s > in_f || post_s > post_f)
        return;
    
    int root = post[post_f];
    int in_Rpos = in_temp[root];
    
    printf("%d ", root);
    sol(in_s, in_Rpos-1, post_s, post_s + (in_Rpos -1 - in_s));
    sol(in_Rpos+1, in_f, post_s + (in_Rpos -1 - in_s)+1, post_f-1);
}

int main (void) {
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &in[i]);
        in_temp[in[i]] = i;
    }
    
    for(int i=0; i<n; i++){
        scanf("%d", &post[i]);
    }
    
    sol(0, n-1, 0, n-1);
}
