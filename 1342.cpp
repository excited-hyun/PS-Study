#include <iostream>
#include <cstdio>
#include <string.h>

char inArr[11];
char newArr[11];
int check[11];
int dupli[26];
int lenArr;
int result;

void checkLuck(){
    for(int i=0; i<lenArr-1; i++){
        if(newArr[i]==newArr[i+1])
            return;
    }
    result++;
}

void dfs(int cnt){
    if(cnt == lenArr){
        checkLuck();
        //printf("a\n");
        return;
    }
    
    for(int i=0; i<lenArr; i++){
        if(check[i])
            continue;
        newArr[cnt] = inArr[i];
        check[i] = 1;
        dfs(cnt+1);
        check[i] = 0;
    }
}

int main() {
    
    int dup_num=1;
    
    scanf("%s", inArr);
    lenArr = strlen(inArr);
    
    //한글자씩 추가해 전부 확인
    for(int i=0; i<lenArr; i++){
        newArr[0] = inArr[i];
        check[i] = 1;
        dfs(1);
        check[i] = 0;
    }
    
    //중복되는 알파벳있는 경우 각각이 몇번 나오는지
    for(int i=0; i<lenArr; i++)
        dupli[inArr[i]-'a']++;
    
    //중복제거를 위해 나눠줄 값 연산
    for(int i=0; i<26; i++){
        for(int j=2; j<=dupli[i]; j++)
            dup_num *= j;
    }
    
    printf("%d\n", result/dup_num);
}
