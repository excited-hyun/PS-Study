
#include <stdio.h>

void Swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int Partition(int arr[], int left, int right)
{
    int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
    int low = left + 1;
    int high = right;
 
    while (low <= high) // 교차되기 전까지 반복한다
    {
        while (low <= right && pivot >= arr[low]) // 피벗보다 큰 값을 찾는 과정
        {
            low++; // low를 오른쪽으로 이동
        }
        while (high >= (left+1)  && pivot <= arr[high]) // 피벗보다 작은 값을 찾는 과정
        {
            high--; // high를 왼쪽으로 이동
        }
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행
        {
            Swap(arr, low, high); //low와 high를 스왑
        }
    }
    Swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환
    return high;  // 옮겨진 피벗의 위치정보를 반환
 
}
 
 
void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1); // 왼쪽
        QuickSort(arr, pivot + 1, right); // 오른쪽
    }
}

int main (void){
    int n, i, j;
    int arr[10000];
    int result = 0;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    QuickSort(arr,0,n-1);
    
    for(i=0; i<n; i++){
        if(arr[i] <= 0 && arr[i+1] <= 0 && i+1<n){
            result += arr[i]*arr[i+1];
            i++;
        }
        else if(arr[i] > 0){
            break;
        }
        else{
            result += arr[i];
        }
    }
    
    if(i==n-1){
        if(n==1){
            printf("%d\n", arr[i]);
            return 0;
        }
        else if(arr[i] > 0){
            printf("%d\n", arr[i] + result);
            return 0;
        }
        printf("%d\n", result);
        return 0;
    }

    for(j=n-1; j>= i; j--){
        if(arr[j] > 0 && arr[j-1] > 0 && j-1 >=i){
            if(arr[j]*arr[j-1] > arr[j] + arr[j-1]){
                result += arr[j]*arr[j-1];
                j--;
            }
            else{
                result += arr[j];
            }
        }
        else{
            result += arr[j];
        }
    }
    
    printf("%d\n", result);
}
