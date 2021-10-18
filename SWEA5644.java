import java.util.Scanner;
import java.util.*;

public class Solution {

	static int M, A;
	static int[] moveA;
	static int[] moveB;
	static Pos[] BC;

	static int[] R = {0, -1, 0, 1, 0};
	static int[] C = {0, 0, 1, 0, -1};

	static int aR = 1;
	static int aC = 1;
	static int bR = 10;
	static int bC = 10;

	static int answer;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		for(int tc = 1; tc<=T; tc++) {
			answer = 0;
			
			M = sc.nextInt();
			A = sc.nextInt();

			moveA = new int[M];
			moveB = new int[M];

			aR = 1;
			aC = 1;
			bR = 10;
			bC = 10;

			for(int i=0; i<M; i++) {
				moveA[i] = sc.nextInt();
			}

			for(int i=0; i<M; i++) {
				moveB[i] = sc.nextInt();
			}

			BC = new Pos[A];

			for(int i=0; i<A; i++) {
				int c = sc.nextInt();
				int r = sc.nextInt();

				int cover = sc.nextInt();
				int perform = sc.nextInt();

				BC[i] = new Pos(r, c, cover, perform);
			}

			charge();
			//움직이면서 충전 
			for(int i=0; i<M; i++) {
				aR += R[moveA[i]];
				aC += C[moveA[i]];
				bR += R[moveB[i]];
				bC += C[moveB[i]];
				charge();
			}
			
			System.out.println("#"+tc+ " "+answer);
		}

	}

	static void charge() {
		int[] canA = new int[A];
		int[] canB = new int[A];
		int cntA = 0, cntB=0;

		for(int i=0; i<A; i++) {
			Pos p = BC[i];

			// A충전 가능 
			if(Math.abs(aR - p.r)+Math.abs(aC-p.c) <= p.cover) {
				canA[i] = 1;
				cntA++;
			}

			// B충전 가능 
			if(Math.abs(bR - p.r)+Math.abs(bC-p.c) <= p.cover) {
				canB[i] = 1;
				cntB++;
			}
		}
		
		int maxC = 0;
		
		//둘 다 충전 불가 
		if(cntA == 0 && cntB == 0) {
			return;
		}
		
		// A만 가능
		if(cntB == 0) {
			maxC = 0;
			for(int i=0; i<A; i++) {
				if(canA[i] == 0)
					continue;
				
				Pos p = BC[i];
				
				if(maxC < p.perform) {
					maxC = p.perform;
				}
			}
			answer+=maxC;
				
			return ;
		}
		
		// B만 가능
		if(cntA == 0) {
			maxC = 0;
			for(int i=0; i<A; i++) {
				if(canB[i] == 0)
					continue;
				
				Pos p = BC[i];
				
				if(maxC < p.perform) {
					maxC = p.perform;
				}
			}
			answer+=maxC;
				
			return ;
		}
		
		// 둘다 가능 
		maxC = 0;
		for(int i=0; i<A; i++) {
			
			if(canA[i] == 0)
				continue;
			Pos p1 = BC[i];
			int tempA = p1.perform;
			
			for(int j=0; j<A; j++) {
				if(canB[j] == 0)
					continue;
				Pos p2 = BC[j];
				int tempB = p2.perform;
				
				// 둘이 다른 충전기 
				if(i!=j) {
					if(tempA+tempB >maxC)
						maxC = tempA+tempB;
				}
				// 둘이 같은 충전기 
				else {
					if(tempA > maxC)
						maxC = tempA;
				}
			}
		}
		answer+=maxC;
	}

	static class Pos {
		int r, c, cover, perform;
		Pos(int r, int c, int cover, int perform){
			this.r = r;
			this.c = c;
			this.cover = cover;
			this.perform = perform;
		}
	}

}

