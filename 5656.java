import java.util.Scanner;
import java.util.*;

public class Solution {

	static int N, W, H;
	static int answer;
	static int[][] map;
	static int[] R = {-1, 1, 0 ,0};
	static int[] C = {0, 0, 1, -1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		for(int tc = 1; tc<=T; tc++) {
			
			N = sc.nextInt();
			W = sc.nextInt();
			H = sc.nextInt();
			
			
			map = new int[H+1][W+1];
			int cnt = 0;

			for(int i=1; i<=H; i++) {
				for(int j=1; j<=W; j++) {
					map[i][j] = sc.nextInt();
					if(map[i][j] > 0)
						cnt++;
				}
			}
			

			answer = cnt+1;
			int[][] temp = new int[H+1][W+1];
			for(int x=1; x<=H; x++) {
				for(int y=1; y<=W; y++) {
					temp[x][y] = map[x][y];
				}
			}
			
			
			for(int i=1; i<=W; i++) {
				for(int j=1; j<=H; j++) {
					if(map[j][i] != 0) {
						crushBlock(0, j, i, cnt);
						
						for(int x=1; x<=H; x++) {
							for(int y=1; y<=W; y++) {
								map[x][y] = temp[x][y];
							}
						}
						//System.out.println(j+" "+i+" "+map[j][i]+" "+answer);
						
						break;
					}
				}
			}
			
			
			System.out.println("#"+tc+" "+answer);
		}
	}
	
	static void crushBlock (int broken, int r, int c, int rest) {
		
		Queue<Pos> q = new LinkedList<>();
		int nowR = r;
		int nowC = c;
		/*
		if(rest <= 0) {
			answer = 0;
			return;
		}*/
		if(broken == N) {
			if(rest < answer)
				answer = rest;
			return;
		}
			
		int[][] temp = new int[H+1][W+1];
		
		for(int i=1; i<=H; i++) {
			for(int j=1; j<=W; j++) {
				temp[i][j] = map[i][j];
			}
		}
		
		q.add(new Pos(nowR, nowC, map[nowR][nowC]));
		map[nowR][nowC] = 0;
		rest--;
		
		while(!q.isEmpty()) {
			Pos now = q.poll();
			
			for(int i=1; i<now.br; i++) {
				for(int j=0; j<4; j++) {
					int nextR = now.r+i*R[j];
					int nextC = now.c+i*C[j];
					
					//범위밖
					if(nextR<=0 || nextR>H || nextC<=0 || nextC>W)
						continue;
					
					//이미 사라진 벽돌 
					if(map[nextR][nextC] == 0)
						continue;
					
					// 주변을 더 깰 수 있는 경우 
					else if (map[nextR][nextC] > 1)
						q.add(new Pos(nextR, nextC, map[nextR][nextC]));
					
					map[nextR][nextC] = 0;
					rest--;
					
					
				}
			}
		}
		
		//벽돌 내리기 
		for(int j=1; j<=W; j++) {
			int down = H;
			while(down > 1) {
				if(map[down][j] == 0) {
					int next = down - 1;
                    while(next > 1 && map[next][j] == 0) 
                    	next--;
                    
                    map[down][j] = map[next][j];
                    map[next][j] = 0;

				}
				down--;
			}
		}
		
		// 벽돌 다 깼음 
		if(rest <= 0) {
			answer = 0;
			return;
		}
		
		//다음 벽돌 깨기 
		for(int x=1; x<=H; x++) {
			for(int y=1; y<=W; y++) {
				temp[x][y] = map[x][y];
			}
		}
		
		
		for(int i=1; i<=W; i++) {
			for(int j=1; j<=H; j++) {
				if(map[j][i] != 0) {
					crushBlock(broken+1, j, i, rest);
					for(int x=1; x<=H; x++) {
						for(int y=1; y<=W; y++) {
							map[x][y] = temp[x][y];
						}
					}
					break;
				}
			}
		}
		
		
		
	}
	
	static class Pos{
		int r, c, br;
		
		Pos(int r, int c, int br){
			this.r = r;
			this.c = c;
			this.br = br;
		}
	}

}

