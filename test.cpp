#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int chk_idx;
    bool flag;
    
    for(int i=0; i<array.size(); i++){
        for(int j=1; j<array.size(); j++){
            flag = false;
            chk_idx = i-j;
            if(chk_idx < 0){
                chk_idx = 0;
            }
            if(array[chk_idx] > array[i]){ //큰거 발견
                answer.push_back(chk_idx);
                flag = true;
                break;
            }
            
            chk_idx = i+j;
            if(chk_idx > array.size()-1){
                chk_idx = array.size()-1;
            }
            if(array[chk_idx] > array[i]){ //큰거 발견
                answer.push_back(chk_idx);
                flag = true;
                break;
            }
        }
        if(!flag)
            answer.push_back(-1);
    }
    
    return answer;
}
