import java.util.Scanner;

public class Main {

	static int N, M, K;
	static int[][] map;
	static int[][] temp;
	static int[][] rotation;
	static int[] visited;
	static int[] order;
	static int answer = -1;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		
		map = new int[N][M];
		rotation = new int[K][3];
		visited = new int[K];
		order = new int[K];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		for(int i=0; i<K; i++) {
			rotation[i][0] = sc.nextInt()-1;
			rotation[i][1] = sc.nextInt()-1;
			rotation[i][2] = sc.nextInt();
		}
		
		dfs(0);
		
		System.out.println(answer);
	}
	
	static void dfs(int cnt) {
		if(cnt == K) {
			doRotate();
			return ;
		}
		
		for(int i=0; i<K; i++) {
			if(visited[i] == 1)
				continue;
			visited[i] = 1;
			order[cnt] = i;
			dfs(cnt+1);
			visited[i] = 0;
		}
	}

	static void doRotate() {
		temp = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			System.arraycopy(map[i], 0, temp[i], 0, M);
		}
		
		for(int i=0; i<K; i++) {
			int move = order[i];

			for (int j = 0; j < rotation[move][2]; j++) {
				
				int x1 = rotation[move][0] - rotation[move][2] + j;
				int y1 = rotation[move][1] - rotation[move][2] + j;
				
				int x2 = rotation[move][0] + rotation[move][2] - j;
				int y2 = rotation[move][1] + rotation[move][2] - j;

				rotate(x1, y1, x2, y2);
			}
		}
		
		calcMatrix();
	}
	
	static void rotate(int x1, int y1, int x2, int y2) {
		int tmp1, tmp2;

	    // 윗변 오른쪽 
	    tmp1 = temp[x1][y2];
	    for (int y = y2; y > y1; y--) {
	      temp[x1][y] = temp[x1][y - 1];
	    }

	    // 오른쪽변 아래 
	    tmp2 = tmp1;
	    tmp1 = temp[x2][y2];

	    for (int x = x2; x > x1; x--) {
	      if (x - 1 == x1) {
	        temp[x][y2] = tmp2;
	        continue;
	      }
	      temp[x][y2] = temp[x - 1][y2];
	    }

	    // 아랫변 왼쪽 
	    tmp2 = tmp1;
	    tmp1 = temp[x2][y1];

	    for (int y = y1; y < y2; y++) {
	      if (y + 1 == y2) {
	        temp[x2][y] = tmp2;
	        continue;
	      }

	      temp[x2][y] = temp[x2][y + 1];
	    }

	    // 왼쪽변 위 
	    tmp2 = tmp1;

	    for (int x = x1; x < x2; x++) {
	      if (x + 1 == x2) {
	        temp[x][y1] = tmp2;
	        continue;
	      }

	      temp[x][y1] = temp[x + 1][y1];
	    }
	}
	
	static void calcMatrix() {
		
		for(int i=0; i<N; i++) {
			int sum = 0;
			for(int j=0; j<M; j++) {
				sum+=temp[i][j];
			}
			if(answer == -1 || answer > sum)
				answer = sum;
		}
	}
}

