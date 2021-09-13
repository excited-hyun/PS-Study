import java.util.Scanner;
import java.util.*;

public class Main {
	
	static int n, m;
	static int[] moveR = {1, -1, 0, 0};
	static int[] moveC = {0, 0, 1, -1};
	static int[][] map;
	static int answer = 0;
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		map = new int[n][m];
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		
		makeWall(0);
		
		System.out.println(answer);
	}
	
	//재귀로 3개의 벽 세움
	static void makeWall(int cnt) {
		//3개 다 세우면 바이러스 확인
		if(cnt == 3) {
			int safe = check();
			answer = Math.max(safe, answer);
			return ;
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(map[i][j] == 0) {
					map[i][j] = 1;
					makeWall(cnt+1);
					map[i][j] = 0;
				}
			}
		}
	}
	
	static int check() {
		int result = 0;
		Queue<Pair> q = new LinkedList<>();
		int[][] temp = new int[n][m];
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				temp[i][j] = map[i][j];
				if(map[i][j] == 2)
					q.add(new Pair(i, j));
			}
		}
		
		while(!q.isEmpty()) {
			Pair p = q.remove();
			
			int nowR = p.r;
			int nowC = p.c;
			
			for(int i=0; i<4; i++) {
				int nextR = nowR + moveR[i];
				int nextC = nowC + moveC[i];
				
				if(nextR < 0 || nextR >= n || nextC <0 || nextC >= m)
					continue;
				
				if(temp[nextR][nextC] == 0) {
					temp[nextR][nextC] = 2;
					q.add(new Pair(nextR, nextC));
				}
			}
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(temp[i][j] == 0 )
					result++;
			}
		}
		
		return result;
	}
	
	static class Pair{
		int r;
		int c;
		public Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}
		
	}

}


