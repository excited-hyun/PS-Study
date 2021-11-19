import java.util.Scanner;

public class Main {
	
	final static int MAXCOST = 1000000000;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();

		int[][] bus = new int[n+1][n+1];
		
		// 최댓값 넣어줌 
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i==j)
					continue;
				bus[i][j] = MAXCOST;
			}
		}
		
		// 입력 
		for(int i=0; i<m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			if(c < bus[a][b]) {
				bus[a][b] = c;
			}
		}
		
		// 플로이드-와샬 
		for(int k=1; k<=n; k++) {
			for(int s=1; s<=n; s++) {
				for(int f=1; f<=n; f++) {
					bus[s][f] = Math.min(bus[s][k]+bus[k][f], bus[s][f]);
				}
				
			}
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(bus[i][j] >= MAXCOST)
					System.out.print(0+" ");
				else
					System.out.print(bus[i][j]+" ");
			}
			System.out.println();
		}
		
	}

}

