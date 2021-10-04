import java.util.Scanner;
import java.util.*;

class Pair implements Comparable<Pair> {
	int cnt, num;

	Pair(int cnt, int num) {
		this.cnt = cnt;
		this.num = num;
	}

	public int compareTo(Pair o) {
		if (this.cnt > o.cnt) {
			return 1;
		} else if (this.cnt == o.cnt) {
			return this.num - o.num;
		} else {
			return -1;
		}
	}
}

public class Main {
	static int[][] matrix = new int[101][101];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);


		int r = sc.nextInt();
		r--;
		int c = sc.nextInt();
		c--;
		int k = sc.nextInt();

		int R = 3;
		int C = 3;

		for(int i=0; i<3; i++) {
			for(int j = 0; j<3; j++) {
				matrix[i][j] = sc.nextInt();
			}
		}

		int time = -1;

		for(int l=0; l<=100; l++) {
			if(matrix[r][c] == k) {
				time = l;
				break;
			}

			// R연산 
			if(R>=C) {
				int newC = 0;

				for(int i=0; i<R; i++){
					PriorityQueue<Pair> q1 = new PriorityQueue<Pair>();
					int[] numCnt = new int[101];

					for(int j=0; j<C; j++){

						numCnt[matrix[i][j]]++;
						matrix[i][j] = 0;
					}

					for(int m=1; m<101; m++){
						if(numCnt[m] > 0){

							q1.add(new Pair(numCnt[m], m));
						}
					}

					int index = 0;  

					while(!q1.isEmpty()) {
						//System.out.println(q1.peek().cnt);
						matrix[i][index++] = q1.peek().num;
						matrix[i][index++] = q1.peek().cnt;
						q1.remove();
					}

					//행,열 길이 갱신 (R연산인 경우 열길이만 갱신)
					if(newC < index){
						newC = index;
					}

				}
				C = newC;
			}

			// C연산 
			else {
				int newR = 0;


				for(int i=0; i<C; i++){
					PriorityQueue<Pair> q1 = new PriorityQueue<Pair>();

					int[] numCnt = new int[101];

					for(int j=0; j<R; j++){
						numCnt[matrix[j][i]]++;
						matrix[j][i] = 0;
					}
					for(int m=1; m<101; m++){
						if(numCnt[m] != 0){
							q1.add(new Pair(numCnt[m], m));
						}
					}


					int index = 0;  

					while(!q1.isEmpty()) {
						Pair p = q1.poll();
						matrix[index++][i] = p.num;
						matrix[index++][i] = p.cnt;
					}

					//행,열 길이 갱신 (R연산인 경우 열길이만 갱신)
					if(newR < index){
						newR = index;
					}

				}
				R = newR;
			}

		}
		System.out.println(time);


	}


}

