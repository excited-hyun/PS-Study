#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int a_size = A.size();
    int b_size = B.size();
    
    
    int idx = 0;
    for(int i=0; i<b_size; i++){
        if(B[i] > A[idx]){
            answer++;
            idx++;
        }
    }
    
    return answer;
}
