#include <string>
#include <vector>

using namespace std;

bool check(int cnt, int r, int c, vector<vector<int>> key, vector<vector<int>> lock){
    bool can = true;
    int check = 0;
    int key_size = key.size();
    int lock_size = lock.size();

    for(int i=r; i<r+key_size; i++){
        for(int j=c; j<c+key_size; j++){
            
            if(i<0 || j<0 || i>=lock_size || j>= lock_size)
                continue;
            
            //열쇠구멍이랑 안맞음
            if(lock[i][j] == key[i-r][j-c]){
                can = false;
                return can;
            }
            //맞는 구멍수 count
            else if(lock[i][j] == 0 && key[i-r][j-c] == 1)
                check++;
        }
    }
    //열쇠칸에 자물쇠 빈칸 수가 안 맞음
    printf("%d %d\n", check, cnt);
    if(check!= cnt)
        can = false;
    return can;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int key_size = key.size();
    int lock_size = lock.size();
    int cnt = 0;
    
    vector<vector<int>> temp;
    //temp 크기
    temp.resize(key_size);
    for(int i=0; i<key_size; i++)
        temp[i].resize(key_size);
    
    //자물쇠의 빈칸 count
    for (int i=0; i<lock_size; i++){
        for(int j=0; j<lock_size; j++){
            if(lock[i][j] == 0)
                cnt++;
        }
    }
    if(cnt == 0)
        return true;
    //모든 위치에 대해서
    for (int i=-key_size+1; i<lock_size; i++){
        for(int j=-key_size+1; j<lock_size; j++){
            //키 4방향 돌리기
            for(int k=0; k<4; k++){
                //90도 회전해 temp에 저장했다가 다시 key에 저장
                for(int l = 0; l < key_size; l++){
                    for(int m = 0; m < key_size; m++){
                        temp[m][key_size-l-1] = key[l][m];
                    }
                }
                for(int l = 0; l < key_size; l++){
                    for(int m = 0; m < key_size; m++){
                        key[l][m] = temp[l][m];
                    }
                }
                
                //check함수 호출해 열 수 있는지 확인
                if(check(cnt, i, j, key, lock) == true){
                    answer = true;
                    return answer;
                }
            }
            
        }
    }
    
    return answer;
}
