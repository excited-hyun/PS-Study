#include<iostream>
#include<cstdio>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    int w_time;
    int now; //a=1, b=0
    int a_time[1001], b_time[1001];
    int a_b[1001], b_a[1001];
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%d %d %d %d", &a_time[i], &b_time[i], &a_b[i], &b_a[i]);
    }
    scanf("%d %d", &a_time[n], &b_time[n]);
 
    if(a_time[1] > b_time[1]){
        w_time = b_time[1];
        now = 0;
    }
    else{
        w_time = a_time[1];
        now = 1;
    }
    
    for(int i=1; i<n; i++){
        if(now == 1){    //a
            if(a_b[i]+b_time[i+1] < a_time[i+1]){
                w_time += a_b[i]+b_time[i+1];
                now = 0;
            }
            else{
                w_time += a_time[i+1];
                now = 1;
            }
            
        }
        else{   //b
            if(b_a[i]+a_time[i+1] < b_time[i+1]){
                w_time += b_a[i]+a_time[i+1];
                now = 0;
            }
            else{
                w_time += b_time[i+1];
                now = 1;
            }
        }
    }
    
    printf("%d\n", w_time);
    return 0;
}
