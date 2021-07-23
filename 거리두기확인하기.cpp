#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<pair<int, int>> person;

int check_par(vector<string> room, int r1, int c1, int r2, int c2){
    int min_r = min(r1, r2);
    int min_c = min(c1, c2);
    int max_r = max(r1, r2);
    int max_c = max(c1, c2);
    
    //세로로 나란히
    if(r1 == r2){
        if(room[r1][(c1+c2)/2] == 'X')
            return 1;
    }
    //가로로 나란히
    else if(c1 == c2){
        if(room[(r1+r2)/2][c1] == 'X')
            return 1;
    }
    // '\'모양 대각선
    else if(r2 == max_r && c2 == max_c){
        if(room[max_r-1][max_c] == 'X' && room[max_r][max_c-1] == 'X')
            return 1;
    }
    // '/'모양 대각선
    else if (r2 == max_r && c1 == max_c){
        if(room[min_r][min_c] == 'X' && room[max_r][max_c] == 'X')
            return 1;
    }
    
    
    return 0;   //파티션 안 지켜짐
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int sw=1;   //각 대기실의 거리두기가 잘 지켜지고 있는지
    
    for (int i=0; i<5; i++){
        person.clear();
        
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                //응시자 있는 위치들 벡터에 추가
                if(places[i][j][k] == 'P')
                    person.push_back(make_pair(j, k));;
            }
        }
        
        //응시자간의 거리 확인
        sw = 1;
        for(int j=0; j<person.size(); j++){
            int p1_r = person[j].first;
            int p1_c = person[j].second;
            for(int k=j+1; k<person.size(); k++){
                int dist=0;
                int p2_r = person[k].first;
                int p2_c = person[k].second;
                dist = abs(p1_r - p2_r) + abs(p1_c-p2_c);
                
                //거리 안지켜짐
                if(dist <= 2){
                    //파티션도 없음
                    if(check_par(places[i], p1_r, p1_c, p2_r, p2_c) == 0){
                        sw = 0;
                        break;
                    }
                }
            }
            
            if(sw == 0)
                break;
        }
        answer.push_back(sw);
    }
    
    return answer;
}
