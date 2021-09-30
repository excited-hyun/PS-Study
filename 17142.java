import java.util.Scanner;
import java.util.*;

public class Main {
	static int n, m;
	static int[][] map = new int[50][50];
	static int room = 0;
	static int virusCnt = 0;
	static int[] virusR = new int[10];
	static int[] virusC = new int[10];
	static int answer = -1;
	static int[] R = {1, -1, 0, 0};
	static int[] C = {0, 0, 1, -1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		m = sc.nextInt();
		
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				map[i][j] = sc.nextInt();
				if(map[i][j] == 0)
					room++;
				if(map[i][j] == 2) {
					virusR[virusCnt] = i;
					virusC[virusCnt] = j;
					
					virusCnt++;
				}
			}
		}
		
		//원래 빈칸 없는 경우 바로 0 출력 
		if(room == 0) {
			System.out.println(0);
			return ;
		}
		dfs(0, 0);
		
		System.out.println(answer);
		
	}
	
	static void dfs(int idx, int cnt) {
		if(cnt == m) {
			check();
			return;
		}
		if(idx == virusCnt)
			return;
		
		//지금 바이러스 활성화 O
		int r = virusR[idx];
		int c = virusC[idx];
		map[r][c] = -1;
		dfs(idx+1, cnt+1);
		
		//활성화 X
		map[r][c] = 2;
		dfs(idx+1, cnt);
	}
	
	//BFS로 바이러스 퍼지는 시간 확인하는 함수
	static void check() {
		Queue<Virus> q = new LinkedList<>();
		int[][] temp = new int[50][50];
		int nonR = room;
		
		//활성된 바이러스들 큐에 추
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				temp[i][j] = map[i][j];
				if(map[i][j] == -1)
					q.add(new Virus(i, j, 0));
			}
		}
		
		int time = 0;
		
		while(!q.isEmpty()) {
			int nowR = q.peek().r;
			int nowC = q.peek().c;
			int nowT = q.peek().time;
			q.remove();
			
			for(int i=0; i<4; i++) {
				int nextR = nowR + R[i];
				int nextC = nowC + C[i];
				
				if(nextR<0 || nextR>=n || nextC<0 || nextC>=n)
					continue;
				//이미 바이러스 퍼트린 구역 or 
				if(temp[nextR][nextC] == 1 || temp[nextR][nextC] < 0)
					continue;
				
				// 비활성 바이러스 있던 곳이 아닌 빈칸!
				if(temp[nextR][nextC]==0)
					nonR--;
				
				//바이러스 퍼트린 위치는 -값 갖도록함
				temp[nextR][nextC] = -(nowT+1);
				q.add(new Virus(nextR, nextC, nowT+1));
				
			}
			//바이러스 다 퍼트린 경우 bfs종료!
			if(nonR == 0) {
				time = nowT+1;
				break;
			}
		}
		//바이러스 퍼트리기 성공 
		if(nonR == 0) {
			if(answer == -1)
				answer = time;
			else if(time < answer)
				answer = time;
		}
		//System.out.println();
	}
	
	static class Virus{
		int r;
		int c;
		int time;
		public Virus(int r, int c, int time) {
			this.r = r;
			this.c = c;
			this.time = time;
		}
		
	}
}

