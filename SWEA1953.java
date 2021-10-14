import java.util.*;

public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for(int tc = 1; tc<=T; tc++) {

			Queue<Pos> q = new LinkedList<>();

			int N = sc.nextInt();
			int M = sc.nextInt();
			int R = sc.nextInt();
			int C = sc.nextInt();
			int L = sc.nextInt();

			int[][] moveR = {{0,0,0,0},{-1,1,0,0},{-1,1,0,0},{0,0,0,0},{-1,0,0,0},{0,1,0,0},{0,1,0,0},{-1,0,0,0}};
			int[][] moveC = {{0,0,0,0},{0,0,-1,1},{0,0,0,0},{0,0,-1,1},{0,0,0,1},{0,0,0,1},{0,0,-1,0},{0,0,-1,0}};

			int[][] canMove = {{1, 2, 5, 6}, {1, 2, 4, 7}, {1, 3, 4, 5}, {1, 3, 6, 7}};
			int[][]map = new int[N][M];

			for(int i=0; i<N; i++) {
				for(int j=0; j<M; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			q.add(new Pos(R, C, 1));

			int[][] visited = new int[N][M];
			visited[R][C] = 1;

			int answer = 1;

			while(!q.isEmpty()) {
				Pos now = q.poll();

				//System.out.println(now.r+" "+now.c+" "+now.time);

				int type = map[now.r][now.c];

				for(int i=0; i<4; i++) {
					int nextR = now.r+moveR[type][i];
					int nextC = now.c+moveC[type][i];

					if(nextR<0 || nextR>=N || nextC<0 || nextC>=M)
						continue;
					if(visited[nextR][nextC] == 1 || map[nextR][nextC] == 0)
						continue;

					for(int j=0; j<4; j++) {
						if(map[nextR][nextC] == canMove[i][j]) {
							if(now.time < L) {
								visited[nextR][nextC] = 1;
								q.add(new Pos(nextR, nextC, now.time+1));
								answer++;
							}
						}
					}

				}
			}


			System.out.println("#"+tc+" "+answer);

		}
	}

	static class Pos {
		int r, c, time;
		Pos (int r, int c, int time){
			this.r = r;
			this.c = c;
			this.time = time;
		}
	}

}

