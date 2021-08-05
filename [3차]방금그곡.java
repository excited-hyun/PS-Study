import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;


class Solution {
    public String solution(String m, String[] musicinfos) {
        String answer = "";
        Map<Integer, String> map1 = new HashMap<>();
        int size = musicinfos.length;
        
        //재생시간 동일한 경우 먼저 입력된 제목을 답으로 하기 위해 musicinfos를 뒤부터 탐색
        for(int j=size-1; j>=0; j--){
            String data = musicinfos[j];
            ArrayList<Integer> idxList = new ArrayList<Integer> ();    //등장위치
            String[] array = data.split(",");    //시작시간, 끝시간, 제목, 악보
            
            //시간 계산
            String[] s_time = array[0].split(":");
            String[] e_time = array[1].split(":");
            //분으로 변환
            int s_hour = Integer.parseInt(s_time[0]);
            int s_min = Integer.parseInt(s_time[1]);
            int e_hour = Integer.parseInt(e_time[0]);
            int e_min = Integer.parseInt(e_time[1]);
            
            s_min = s_min+s_hour*60;
            e_min = e_min+e_hour*60;
            int total_time = e_min - s_min;
            
            //#개수 count
            int cnt=0;
            for(int i=0; i<array[3].length(); i++) {
                if(array[3].charAt(i)=='#') {
                    cnt++;
                }
            }
            String sheet = "";
            int play_time = total_time;
            int play_len = array[3].length()-cnt;
            //재생시간이 악보 길이보다 긴 경우
            while(play_time >= play_len){
                sheet += array[3];
                play_time -= play_len;
            }
            
            //위의 처리 후 남은 재생시간이 있는 경우
            int end_idx=-1;
            if(play_time < play_len){
                for(int i=0; i<array[3].length(); i++){
                    
                    sheet+=array[3].charAt(i);
                    if(i == array[3].length()-1)
                        continue;
                    //다음꺼가 #인 경우 추가
                    if(array[3].charAt(i+1) == '#'){
                        sheet+=array[3].charAt(i+1);
                        i++;
                    }
                    
                    play_time--;
                    if(play_time < 0){
                        end_idx = i;
                        break;
                    }
                }
            }
            if(end_idx!=-1 && end_idx<array[3].length()-1){
                if(array[3].charAt(end_idx+1) == '#')
                    sheet+=array[3].charAt(end_idx+1);
            }
            
            //등장위치 모두 찾음
            int idx = sheet.indexOf(m);
            while(idx != -1){
                idxList.add(idx);
                idx = sheet.indexOf(m, idx+m.length());
            }
            
            if(idxList.size() == 0)
                continue;
            
            //등장 안함.
            int sw = 0;
            //등장하는데, 뒤에 #이 붙는지 확인
            for(int i=0; i<idxList.size(); i++){
                int check = idxList.get(i)+m.length();
                
                if(check >= sheet.length())
                    break;
                if(sheet.charAt(check)!='#'){
                    sw = 1;
                    break;
                }
            }
            if(sw == 0)
                continue;
            
            //추가
            map1.put(total_time, array[2]);
            
        }
        //Map 확인
        Set<Map.Entry<Integer, String>> entries = map1.entrySet();
        int time = 0;
        for(Map.Entry<Integer,String> tempEntry: entries) {
            if(time < tempEntry.getKey()){
                time = tempEntry.getKey();
                answer = tempEntry.getValue();
            }
        }
        
        //Map이 비었던 경우는 time이 그대로 0으로 남게됨.
        if(time == 0)
            answer = "(None)";
        
        return answer;
    }
}
