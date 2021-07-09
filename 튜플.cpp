#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string temp;
    vector<pair<int, string>> save;
    int num;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '{'){
            temp = "";
        }
        else if(s[i] == '}'){
            if (temp.length()!=0){
                save.push_back(make_pair(temp.length(), temp));
                temp="";
            }
        }
        else{
            temp = temp+s[i];
        }
    }
    sort(save.begin(), save.end());
    
    for(int i=0; i<save.size(); i++){
        int j=0;
        while(j < save[i].first){
            sscanf(save[i].second.c_str(),"%d", &num);  //숫자 하나씩
            
            save[i].second.erase(0, to_string(num).length()+1); //그 숫자 지움
            j+=to_string(num).length()+1;
            vector<int>::iterator it;
            it = find(answer.begin(), answer.end(), num);
            if(it==answer.end())        //아직 벡터에 없을 때만 추가
                answer.push_back(num);
        }
    }
    return answer;
}
