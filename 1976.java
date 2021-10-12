import java.util.Scanner;
import java.util.*;

public class Main {

	static int N, M;
	static int[][] way;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		
		way = new int[N+1][N+1];
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				way[i][j] = sc.nextInt();
			}
		}
		
		int start = sc.nextInt();
		for(int i=0; i<M-1; i++) {
			int dest = sc.nextInt();
			
			//현재 이동이 불가능 
			if(check(start, dest) == false) {
				System.out.println("NO");
				return;
			}
			
			// 다음 확인을 위해 목적지를 출발지로 바꿔 줌 
			start = dest;
		}
		System.out.println("YES");

	}
	
	// start에서 dest로 이동이 가능한지 확인하는 함수 
	static boolean check(int start, int dest) {
		Queue<Integer> q = new LinkedList<>();
		int[] visited = new int[N+1];
		
		q.add(start);
		visited[start] = 1;
		
		while(!q.isEmpty()) {
			int now = q.poll();
			
			if(now == dest)
				return true;
			
			for(int i=1; i<=N; i++) {
				
				if(way[now][i] == 0 || visited[i] == 1)
					continue;
				visited[i] = 1;
				q.add(i);
				
			}
		}
		return false;
	}

}

