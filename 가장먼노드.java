import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        
        int answer = 0;
        List<Integer>[] arr = new ArrayList[n + 1];
        int[] visited = new int[n+1];
        Queue<Pair> q = new LinkedList<>();

        for (int i = 0; i < n+1; ++i) {
	        arr[i] = new ArrayList<Integer>();
        }
        
        // edge를 양방향으로 저장
        for(int i=0; i<edge.length; i++){
            int a = edge[i][0];
            int b = edge[i][1];
            arr[a].add(b);
            arr[b].add(a);
        }
        
        // 이동횟수 0, 시작점 1 큐에 add
        q.add(new Pair(0, 1));
        visited[1] = 1;
        int maxMove = 0;
        
        // BFS
        while(!q.isEmpty()){
            int move = q.peek().first;
            int now = q.peek().second;
            q.remove();
            // 현재 이동 거리가 최대
            if(maxMove == move)
                answer++;
            // 더 먼 노드 발견 -> 최대, 갯수 갱신
            else if(maxMove < move){
                answer = 1;
                maxMove = move;
            }
            for(int i=0; i<arr[now].size(); i++){
                int next = arr[now].get(i);
                if(visited[next] == 1)     //이미 방문
                    continue;
                // 아직 미방문
                visited[next] = 1;
                q.add(new Pair(move+1, next));
            }
        }
        
        return answer;
    }
    
}

class Pair implements Comparable<Pair> {
    int first, second;
    
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
    
    public int compareTo(Pair p) {
        if(this.first < p.first) {
            return -1; // 오름차순
        }
        else if(this.first == p.first) {
            if(this.second < p.second) {
                return -1;
            }
        }
        return 1;
    }
}
