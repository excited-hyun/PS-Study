#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    int half = s.length() / 2;
    string com = "";
    string now = "";
    answer = len;
    int check = len;
    int cnt;
    for(int i=1; i<=half; i++){
        check = len;
        com = s.substr(0, i);
        cnt = 1;
        for(int j=i; j<len; j+=i){
            now = s.substr(j, i);
            if(now == com){
                if(cnt == 1 || cnt == 9 || cnt == 99 || cnt == 999){
                    check -= i;
                    check++;
                    cnt++;
                }
                else {
                    check-=i;
                    cnt++;
                }
            }
            else{
                com = s.substr(j, i);
                cnt = 1;
            }
        }
        if(check < answer)
            answer = check;
    }
    return answer;
}
