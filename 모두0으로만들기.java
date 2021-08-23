import java.util.*;

class Solution {
    long answer = 0;
    long tmp[]; 
    int visit[];
    List<Integer>[] edgeList;
    
    public long solution(int[] a, int[][] edges) {
        
        int len = a.length;
        tmp = new long[len];
        visit = new int[len];
        long sum = 0;
        edgeList = new ArrayList[len];
        for(int i = 0; i < len; i++) {
			sum += a[i];
            tmp[i] = a[i];
            edgeList[i] = new ArrayList<Integer>();
	    }
        //불가능
        if(sum!=0)
            return -1;
        
        for(int i = 0; i < edges.length; i++) {
	    	edgeList[edges[i][0]].add(edges[i][1]);
	    	edgeList[edges[i][1]].add(edges[i][0]);
		}
        
        dfs(0);
        
        return answer;
    }
    
    long dfs(int node){
        visit[node] = 1;
        for(int i=0; i<edgeList[node].size(); i++){
            int next = edgeList[node].get(i);
            if(visit[next]==1)
                continue;
            tmp[node] += dfs(next);
            
        }
        long num = tmp[node];
        answer += Math.abs(num);
        return num;
    }
}
