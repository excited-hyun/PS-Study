import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int[][] map = new int[51][51];
		Scanner sc = new Scanner(System.in);
		int R = sc.nextInt();
		int C = sc.nextInt();
		int T = sc.nextInt();
		
		// 공기청정기 위치 
		int up = -1;
		int down = -1;
		
		int[] X = {1, -1, 0, 0};
		int[] Y = {0, 0, 1, -1};
		
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				map[i][j] = sc.nextInt();
				
				// 공기청정기 위치 저장 
				if(map[i][j] == -1) {
					if(up == -1) {
						up = i;
					}
					else {
						down = i;
					}
				}
			}
		}
		
		
		
		for(int k=0; k<T; k++) {
			int[][] temp = new int[51][51];
			
			//먼지 확산!
			for(int i=0; i<R; i++) {
				for(int j=0; j<C; j++) {
					temp[i][j] += map[i][j];
					
					if(map[i][j] < 5)
						continue;
					
					int munji = map[i][j] / 5;
					
					//먼지 상하좌우로 확산
					int cnt=0;
					for(int l = 0; l<4; l++) {
						int nextR = i + X[l];
						int nextC = j + Y[l];
						if(nextR<0 || nextR>=R || nextC<0 || nextC>=C)
							continue;
						
						if(map[nextR][nextC] == -1)
							continue;
						
						temp[nextR][nextC]+=munji;
						cnt++;
					}
					
					temp[i][j] -= (munji*cnt);
				}
			}
			

			// map에 옮기기 
			for(int i=0; i<R; i++) {
				for(int j=0; j<C; j++) {
					map[i][j] = temp[i][j];
				}
			}
			
			
			//공기청정기 작동!
			
			// ->
			map[up][1] = 0;
			map[down][1] = 0;
			for(int i=2; i<C; i++) {
				map[up][i] = temp[up][i-1];
				map[down][i] = temp[down][i-1];
			}
			
			// up - 위
			for(int i=up-1; i>=0; i--) {
				map[i][C-1] = temp[i+1][C-1];
			}
			
			// down - 아래
			for(int i=down+1; i<R; i++) {
				map[i][C-1] = temp[i-1][C-1];
			}
			
			// <-
			for(int i=C-2; i>=0; i--) {
				map[0][i] = temp[0][i+1];
				map[R-1][i] = temp[R-1][i+1];
			}
			
			// up - 아래
			for(int i=1; i<up; i++) {
				map[i][0] = temp[i-1][0];
			}
			
			// down - 위
			for(int i=R-2; i>down; i--) {
				map[i][0] = temp[i+1][0];
			}
			
		}
		
		int answer = 0;
		
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				if(map[i][j] > 0 )
					answer+=map[i][j];
			}
		}
		
		System.out.println(answer);

	}

}

