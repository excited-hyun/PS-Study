import java.util.Scanner;
import java.util.*;

public class Solution {

	static int N, K;
	static int[][] map;
	static int[][] visited;
	static int answer;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		for(int i=0; i<T; i++) {
			N = sc.nextInt();
			K = sc.nextInt();
			map = new int[N][N];
			answer = 0;
			int maxH = 0;
			
			Queue<Pos> q = new LinkedList<>();
			
			for(int j=0; j<N; j++) {
				for(int l = 0; l<N; l++) {
					map[j][l] = sc.nextInt();
					
					if(map[j][l] == maxH) {
						q.add(new Pos(j, l));
						
					}
					
					else if(map[j][l] > maxH) {
						maxH = map[j][l];
						q.clear();
						q.add(new Pos(j, l));
					}
				}
			}
			
			while(!q.isEmpty()) {
				
				Pos top = q.poll();
				
				visited = new int[N][N];
				visited[top.r][top.c] = 1;
	
				dfs(1, top.r, top.c, false);
			}
			
			System.out.println("#"+(i+1)+" "+answer);
			
		}
	}
	
	static void dfs(int road, int nowR, int nowC, boolean cut) {
		
		if(road > answer)
			answer = road;
		
		int[] R = {1, -1, 0, 0};
		int[] C = {0, 0, 1, -1};
		
		
		
		for(int i=0; i<4; i++) {
			int nextR = nowR+R[i];
			int nextC = nowC+C[i];
			
			//System.out.println(nowR+" "+nowC+" "+road+" "+cut+" "+nextR+" "+nextC+" "+map[nowR][nowC]);
			
			if(nextR<0 || nextR>=N || nextC<0||nextC>=N)
				continue;
			
			if(visited[nextR][nextC] == 1)
				continue;
			
			//그냥 길 생성 가능 
			if (map[nowR][nowC] > map[nextR][nextC]) {
				visited[nextR][nextC] = 1;
				dfs(road+1, nextR, nextC, cut);
				visited[nextR][nextC]= 0;
			}
			
			// 깎아야함.
			else if(map[nowR][nowC] <= map[nextR][nextC] && cut == false) {
				int temp = map[nextR][nextC];
				
				if(map[nextR][nextC] - map[nowR][nowC] < K) {
					map[nextR][nextC] = map[nowR][nowC] - 1;
					visited[nextR][nextC] = 1;
					dfs(road+1, nextR, nextC, true);
					map[nextR][nextC] = temp;
					visited[nextR][nextC]= 0;
				}
			}
			
			
		}
		
	}
	
	
	static class Pos {
		int r, c;
		Pos(int r, int c){
			this.r = r;
			this.c = c;
			
		}
	}

}

