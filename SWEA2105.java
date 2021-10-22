package swea2105;

import java.util.*;

public class Solution {

	static int N;
	static int[][] map;
	static int answer;

	static int[] moveR = {1, 1, -1, -1};
	static int[] moveC = {1, -1, -1, 1};
	static HashSet<Integer> set = new HashSet<Integer>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		for(int tc = 1; tc<=T; tc++) {
			N = sc.nextInt();
			map = new int[N][N];
			answer = -1;

			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					map[i][j] = sc.nextInt();
				}
			}

			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					set.clear();
					set.add(map[i][j]);


					move(i, j, i, j, 0, 0);
				}
			}

			System.out.println("#"+tc+" "+answer);

		}

	}

	static void move(int nowR, int nowC, int sR, int sC, int rd, int ld) {
		if(rd!=0 && ld!=0) {
			HashSet<Integer> check = new HashSet<Integer>();

			check.addAll(set);
			int nextR = nowR;
			int nextC = nowC;
			int sw = 1;

			//왼 위 이동 
			for(int i=0; i<rd; i++) {
				nextR = nextR+moveR[2];
				nextC = nextC+moveC[2];
				if(nextR<0 || nextR>=N || nextC<0 || nextC>=N) {
					sw = 0;
					break;
				}
				if(check.contains(map[nextR][nextC])) {
					sw = 0;
					break;
				}

				check.add(map[nextR][nextC]);

			}
			//오 위 이동
			for(int i=0; i<ld-1; i++) {
				if(sw== 0)
					break;
				nextR = nextR+moveR[3];
				nextC = nextC+moveC[3];
				if(nextR<0 || nextR>=N || nextC<0 || nextC>=N){
					sw = 0;
					break;
				}
				if((nextR!=sR || nextC!=sC)&& check.contains(map[nextR][nextC])){
					sw = 0;
					break;
				}

				check.add(map[nextR][nextC]);
			}
			if(sw==1 && answer < check.size())
				answer = check.size();

		}

		// 오른 아래 이동 
		if(ld==0) {
			int nextR = nowR+moveR[0];
			int nextC = nowC+moveC[0];
			if(nextR>=0 && nextR<N && nextC>=0 && nextC<N) {

				if(!set.contains(map[nextR][nextC])) {

					set.add(map[nextR][nextC]);

					move(nextR, nextC, sR, sC, rd+1, ld);
					set.remove(map[nextR][nextC]);
				}
			}
		}

		// 왼 아래 이동
		if(rd!=0) {
			int nextR = nowR+moveR[1];
			int nextC = nowC+moveC[1];
			if(nextR>=0 && nextR<N && nextC>=0 && nextC<N) {

				if(!set.contains(map[nextR][nextC])) {

					set.add(map[nextR][nextC]);

					move(nextR, nextC, sR, sC, rd, ld+1);
					set.remove(map[nextR][nextC]);
				}
			}
		}

	}

}

