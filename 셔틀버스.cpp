#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> mintable;
    
    //분 단위로 변환
    for (int i = 0; i < timetable.size(); i++)
    {
        int hour = stoi(timetable[i].substr(0, 2));
        int minute = stoi(timetable[i].substr(3, 2));
        int time = hour * 60 + minute;
        mintable.push_back(time);
    }
    sort(mintable.begin(), mintable.end());

    int start = 9*60 - t;   //셔틀 시간
    int result;
    int idx = 0;
    int cnt;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        start +=t;
        //이번 버스 타는 사람 수 계산
        for (int j = idx; j < mintable.size(); j++)
        {
            if (mintable[j] <= start)
            {
                idx++;
                cnt++;
                if (cnt == m)
                    break;
            }
            
            else
                break;
        }
 
        //마지막 셔틀일 때
        if (i == n-1)
        {
            //자리 없음
            if (cnt == m)
                result = mintable[idx - 1] - 1;
            //자리 남음
            else
                result = start;
        }
    }
    
    //문자열로 변환
    answer += to_string((result/60)/10);
    answer += to_string((result/60)%10);
    answer += ":";
    answer += to_string((result%60)/10);
    answer += to_string((result%60)%10);

    
    return answer;
}
