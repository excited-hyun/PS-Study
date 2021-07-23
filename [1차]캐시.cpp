#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    //캐시 크기가 0
    if(cacheSize == 0){
        answer = cities.size()*5;
        return answer;
    }
    
    
    vector<string> cache;
    for(int i=0; i<cities.size(); i++){
        string check = cities[i];
        transform(check.begin(), check.end(), check.begin(), ::tolower);    // 소문자 변환
        auto it = find(cache.begin(), cache.end(), check);
        //캐시에 있음
        if(it != cache.end()){
            cache.erase(it);
            cache.push_back(check);
            answer++;
            
        }
        //캐시에 없음
        else{
            //캐시에 빈자리 있음
            if(cache.size() < cacheSize)
                cache.push_back(check);
            
            //캐시에 빈자리 없음
            else{
                cache.erase(cache.begin()+0);
                cache.push_back(check);
            }
            answer+=5;
        }
    }
    
    return answer;
}
