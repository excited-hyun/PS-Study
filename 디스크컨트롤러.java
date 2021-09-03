import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        //요청 시간 기준 오름차순
        PriorityQueue<Task> pq1 = new PriorityQueue<>();
        //소요 시간 기준 오름차순
        PriorityQueue<Task> pq2 = new PriorityQueue<>();
        
        
        //모두 시작시간 기준 우선순위 큐에 넣어줌
        int len = jobs.length;
        for(int i=0; i<len; i++){
            pq1.add(new Task(jobs[i][0], jobs[i][1]));
        }
        
        //현재 시간과 비교하여 수행가능한 일들을 다른 우선순위큐에 넣음
        int now = 0;
        while(!pq1.isEmpty()){
            Task t = pq1.peek();
            int sTime = t.first;
            int tTime = t.second;
            
            //현재 시간 이전에 요청된 작업이 소요시간 기준이 되도록 pq2에 넣어줌
            if(sTime <= now){
                pq1.remove();
                pq2.add(new Task(tTime, sTime));
                
            }
            //현재 시간에 수행 가능한 작업 모두 pq2에 넣은 경우 -> pq2에서 하나 뽑아 실행
            else{
                //현재 시간에 수행 가능한 작업 없음 -> 시간 증가 시킴
                if(pq2.isEmpty())
                    now++;
                //pq2의 작업 중 시간 가장 적게 걸리는 것 수행
                else{
                    t = pq2.peek();
                    tTime = t.first;   //소요 시간
                    sTime = t.second;   //시작 시간
                    pq2.remove();
                    now = now + tTime;
                    answer = answer + (now - sTime);
                }
            }
        }
        
        //pq2에 남은 작업 있는 경우 수행
        while(!pq2.isEmpty()){
            Task t = pq2.peek();
            int tTime = t.first;   //소요 시간
            int sTime = t.second;   //시작 시간
            pq2.remove();
            now = now + tTime;
            answer = answer + (now - sTime);
        }
        
        answer = answer / len;
        return answer;
    }
    
    
}

class Task implements Comparable<Task> {
    int first, second;
    
    Task(int first, int second) {
        this.first = first;
        this.second = second;
    }
    
    public int compareTo(Task t) {
        if(this.first < t.first) {
            return -1; // 오름차순
        }
        else if(this.first == t.first) {
            if(this.second < t.second) {
                return -1;
            }
        }
        return 1;
    }
}


