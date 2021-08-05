import java.util.*;

class Solution {
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        int[][] haveRoad = new int[N][N];       //주어진 길 저장
        int[] minRoad = new int[N];        //최단거리 저장
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();//다익스트라에 이용
        
        //haveRoad, minRoad 초기화
        for(int i=0; i<N; i++){
            minRoad[i] = 500001;
            for(int j=0; j<N; j++){
                haveRoad[i][j] = 10001;
            }
        }
        
        //길을 양방향으로 저장
        System.out.println(road.length);
        for(int i=0; i<road.length; i++){
            int a = road[i][0]-1;
            int b = road[i][1]-1;
            int cost = road[i][2];
            if(haveRoad[a][b] > cost){
                haveRoad[a][b] = cost;
                haveRoad[b][a] = cost;
            }
            
        }
        
        //우선순위 큐에 초기위치 저장
        pq.offer(new Pair(0, 0));
        minRoad[0] = 0;
        
        while(!pq.isEmpty()){
            
            Pair now = pq.poll();
            int now_pos = now.pos;
            int now_time = now.time;
            
            for(int i=0; i<N; i++){
                //입력으로 주어진 길이 없음
                if(haveRoad[now_pos][i]==10001)
                    continue;
               
                int new_time = now_time+haveRoad[now_pos][i];
                //새로운 시간이 기존의 시간보다 짧은 경우
                if(minRoad[i] > new_time){
                    minRoad[i] = new_time;
                    pq.offer(new Pair(i, new_time));
                }
            }
        }
        
        //K시간 이하로 배달 가능한 지역 count
        for(int i=0; i<N; i++){
            if(minRoad[i] <= K)
                answer++;
        }

        return answer;
    }
}

class Pair implements Comparable<Pair> {
    int pos, time;
    
    Pair() { }
    
    Pair(int pos, int time) {
        this.pos = pos;
        this.time = time;
    }
    
    public int compareTo(Pair p) {
        return this.time > p.time ? 1 : - 1;
    }
}

