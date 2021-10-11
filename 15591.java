import java.util.Scanner;
import java.util.*;

public class Main {
	
	static int N, Q;

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		
		N = sc.nextInt();
		Q = sc.nextInt();
		
		ArrayList<int[]> [] usado  = new ArrayList[N+1];
		for(int i =1; i < N+1; i++) {
			usado[i] = new ArrayList<int[]>();
		}
		
		for(int i=0; i<N-1; i++) {
			int p1 = sc.nextInt();
			int p2 = sc.nextInt();
			int r = sc.nextInt();
			usado[p1].add(new int[]{p2, r});
            usado[p2].add(new int[]{p1, r});
		}
		
		for(int i=1; i<=Q; i++) {
			int answer = 0;
			
			int k = sc.nextInt();
			int v = sc.nextInt();
			
			Queue<Integer> q = new LinkedList<>();
			
			int[] visited = new int[N+1];
			visited[v] = 1;
			q.add(v);
			
			while(!q.isEmpty()) {
				int now = q.poll();
				for(int[] arr : usado[now] ) {
					int next = arr[0];
					int usa = arr[1];
					if(visited[next] == 1 || usa < k)
						continue;
					answer++;
					visited[next] = 1;
					q.add(next);
				}
			}
			System.out.println(answer);
		}
	}

	
}

