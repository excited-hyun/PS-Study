import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        
        HashMap <String, Integer> m1 = new HashMap<>();
        int size = plays.length;
        
        //장르별 재생 수
        for(int i=0; i<size; i++){
            String g = genres[i];
            int p = plays[i];
            //이미 map에 추가된 장르
            if(m1.containsKey(g)){
                int cnt = m1.get(g);
                m1.put(g, cnt+p);
            }
            //아직 추가되지 않음
            else{
                m1.put(g, p);
            }
        }
        
        //장르에 속한 곡이 하나일 수도 있어서 answer를 배열로 선언해 사용불가
        ArrayList<Integer> temp = new ArrayList<Integer>();  
        
        //value기준으로 내림차순 정렬
        List<String> keyList = new ArrayList<>(m1.keySet());
        Collections.sort(keyList, (o1,o2)->(m1.get(o2).compareTo(m1.get(o1))));
        
        for(int i=0; i<keyList.size(); i++){
            String g = keyList.get(i);
            int firstMax = 0;
            int secondMax = 0;
            int firstIdx = -1;
            int secondIdx = -1;
            for(int j=0; j<size; j++){
                if(genres[j].equals(g)){
                    //이번꺼가 제일 큼
                    if(firstMax < plays[j]){
                        //첫번째를 두번째에 넣고 이번꺼를 첫번째에 넣음
                        secondMax = firstMax;
                        firstMax = plays[j];
                        secondIdx = firstIdx;
                        firstIdx = j;
                    }
                    //제일 큰거보단 작음
                    else {
                        //두번째 보다 큼
                        if(secondMax < plays[j]){
                            //두번째에 넣어줌
                            secondMax = plays[j];
                            secondIdx = j;
                        }
                        //두번째 보다 작으면 그냥 넘어감
                    }
                } 
            }
            //속한 곡이 하나
            if(secondIdx == -1){
                temp.add(firstIdx);
            }
            //둘이상
            else{
                temp.add(firstIdx); 
                temp.add(secondIdx);
            }
        }
        
        //answer 배열에 ArrayList값 옮기기
        int[] answer = new int[temp.size()];
        for(int i=0; i<temp.size(); i++){
            answer[i] = temp.get(i);
        }
        
        return answer;
    }
}
