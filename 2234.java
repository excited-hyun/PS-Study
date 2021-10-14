import java.util.Scanner;
import java.util.*;

public class Main {

	static int N, M;
	static int[][] map;
	static int[] R = {0, -1, 0, 1};
	static int[] C = {-1, 0, 1, 0};
	static int[] check = {1, 2, 4, 8};
	static int[][] visited;
	static int[][] area;
	static ArrayList<Integer> areaSize = new ArrayList<>();
	static int brokenMax;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		map = new int[M][N];


		for(int i=0; i<M; i++) {
			for(int j=0; j<N; j++) {
				map[i][j] = sc.nextInt();
			}
		}

		visited = new int[M][N];
		area = new int[M][N];


		int cnt = 0;
		int maxSize = 0;

		for(int i=0; i<M; i++) {
			for(int j=0; j<N; j++) {
				//BFS
				if(visited[i][j] == 0) {
					visited[i][j] = 1;
					cnt++;
					
					Queue<Pos> q = new LinkedList<>();
					q.add(new Pos(i, j));
					int size = 0;

					while(!q.isEmpty()) {
						Pos now = q.poll();
						int wall = map[now.r][now.c];
						
						//연결된 땅들 끼리는 같은 값갖도록 넣어줌 
						area[now.r][now.c] = cnt;
						size++;

						for(int k=3; k>=0; k--) {
							int nextR = now.r+R[k];
							int nextC = now.c+C[k];

							//벽 있음 
							if(wall / check[k] > 0) {
								wall = wall%check[k];
								continue;
							}

							if(nextR<0||nextR>=M||nextC<0||nextC>=N)
								continue;

							if(visited[nextR][nextC] == 1)
								continue;


							visited[nextR][nextC] = 1;
							q.add(new Pos(nextR, nextC));
						}
					}

					if(size > maxSize)
						maxSize = size;
					
					//해당 구역의 크기 저장 
					areaSize.add(size);

				}
			}
		}


		//벽 하나 뿌시는 경우 확인
		brokenMax = 0;
		for(int i=0; i<M; i++) {
			for(int j=0; j<N; j++) {
				for(int k=0; k<4; k++) {
					int nextR = i+R[k];
					int nextC = j+C[k];

					if(nextR<0||nextR>=M||nextC<0||nextC>=N)
						continue;
					
					//둘이 벽으로 나눠진 구역인 경우 
					if(area[i][j] != area[nextR][nextC]) {
						int sum = areaSize.get(area[i][j]-1);
						sum += areaSize.get(area[nextR][nextC]-1);
						
						if(sum > brokenMax)
							brokenMax = sum;
					}
				}
			}
		}

		System.out.println(cnt);
		System.out.println(maxSize);
		System.out.println(brokenMax);

	}


	static class Pos {
		int r, c;
		Pos(int r, int c){
			this.r = r;
			this.c = c;
		}
	}

	
}


