import java.util.Scanner;
import java.util.*;

public class Solution {

	static int[][] dirChange = {{0, 0, 0, 0}, {1, 2, 3, 0}, {1, 3, 0 ,2}, {3, 0, 1, 2}, {2, 0, 3, 1}, {1, 0, 3, 2}};
	static int[] moveR = {0, 0, -1, 1};
	static int[] moveC = {1, -1, 0, 0};
	
	static int[][] map;
	static ArrayList<Pos>[] wormhole;
	
	static int N;
	static int answer;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		for(int tc = 1; tc<= T; tc++) {
			N = sc.nextInt();
			map = new int[N][N];
			wormhole = new ArrayList[5];
			
			for(int i=0; i<5; i++) {
				wormhole[i] = new ArrayList<>();
			}
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					map[i][j] = sc.nextInt();
					if(map[i][j] >= 6) {
						wormhole[map[i][j]-6].add(new Pos(i, j));
					}
				}
			}
			
			
			answer = 0;
		
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(map[i][j]!=0)
						continue;
					for(int dir=0; dir<4; dir++) {
						
						int score = check(i, j, dir);
						if(score > answer)
							answer = score;
						
					}
				}
			}
			
			System.out.println("#"+tc+" "+answer);
		}

	}
	
	static int check(int r, int c, int dir) {
		int score = 0;
		
		int nowR = r;
		int nowC = c;
		int move = 0;
		
		while(true) {
			
			//제자리로 
			if(nowR == r && nowC == c && move !=0) 
				break;
			
			//블랙
			if(map[nowR][nowC] == -1)
				break;
			
			nowR = nowR + moveR[dir];
			nowC = nowC + moveC[dir];
			move++;
			
			
			//벽에 부딪힘 
			if(nowR<0 || nowR>=N || nowC<0 || nowC>=N) {
				nowR = nowR - moveR[dir];
				nowC = nowC - moveC[dir];
				
				if(dir == 0)
					dir = 1;
				else if(dir == 1)
					dir = 0;
				else if(dir == 2)
					dir = 3;
				else if(dir == 3)
					dir = 2;
				
				score++;
				
			}
			
			//블록에 부딪힘 
			if(map[nowR][nowC] >= 1 && map[nowR][nowC] <=5) {
				int block = map[nowR][nowC];
				
				dir = dirChange[block][dir];
				score++;
				continue;
			}
			
			//웜홀
			if(map[nowR][nowC] > 5) {
				int block = map[nowR][nowC];
				int r1 = wormhole[block-6].get(0).r;
				int c1 = wormhole[block-6].get(0).c;
				
				int r2 = wormhole[block-6].get(1).r;
				int c2 = wormhole[block-6].get(1).c;
				
				if(nowR == r1 && nowC == c1) {
					nowR = r2;
					nowC = c2;
				}
				else {
					nowR = r1;
					nowC = c1;
				}
			}
			
			
		}
		
		return score;
	}
	
	static class Pos {
		int r, c;
		Pos(int r, int c){
			this.r = r;
			this.c = c;
		}
		
	}

}

