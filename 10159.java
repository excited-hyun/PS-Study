import java.util.Scanner;

public class Main {

	static int N, M;
	static int[][] matrix;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		
		matrix = new int[N+1][N+1];
		for(int i=0; i<M; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			matrix[a][b] = 1;
			matrix[b][a] = -1;
		}
		
		for(int k=1; k<=N; k++) {
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					if(matrix[i][k] == matrix[k][j] && matrix[i][k]!=0)
						matrix[i][j] = matrix[i][k];
				}
			}
		}
		
		for(int i=1; i<=N; i++) {
			int ans = 0;
			for(int j=1; j<=N; j++) {
				if(i == j)
					continue;
				
				if(matrix[i][j] == 0 && matrix[j][i] == 0)
					ans++;
			}
			System.out.println(ans);
		}
		
	}

}

