
import java.util.Scanner;

public class Main {

	static int N, K, answer;
	static int[] kit;
	static int[] day;
	static int[] visited;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		K = sc.nextInt();
		kit = new int[N];
		day = new int[N];
		visited = new int[N];
		
		for(int i=0; i<N; i++)
			kit[i] = sc.nextInt();
		
		dfs(0);
		
		System.out.println(answer);
		
	}
	
	static void dfs(int cnt) {
		if(cnt == N) {
			boolean result = check();
			if(result)
				answer++;
			return;
		}
		
		
		for(int i=0; i<N; i++) {
			if(visited[i] == 1)
				continue;
			visited[i] = 1;
			day[cnt] = i;
			dfs(cnt+1);
			visited[i] = 0;
		}
		
	}
	static boolean check() {
		int nowW = 500;
		for(int i=0; i<N; i++) {
			int idx = day[i];
			
			nowW += kit[idx];
			nowW -= K;
			if(nowW < 500)
				return false;
		}
		return true;
	}

}

