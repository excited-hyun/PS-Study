import java.util.Scanner;

public class Main {
	
	static int A, B, C;
	static int sum;
	static int[][] visited;
	static boolean answer = false;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();
		
		sum = A+B+C;
		visited = new int[sum+1][sum+1];
		
		if(sum %3 != 0) {
			System.out.println("0");
			return;
		}
		else {
			dfs(A, B);
		}
		
		System.out.println(visited[sum/3][sum/3]);
	}

	static void dfs(int a, int b) {
		if (visited[a][b] == 1) 
			return;
	    visited[a][b] = 1;

	    int[] rock = {a, b, sum - (a + b)};

	    for (int i = 0; i < 3; i++){
	        for (int j = 0; j < 3; j++){
	            if (rock[i] < rock[j]){
	                int[] temp = {a, b, sum - (a + b)};
	                temp[i] += rock[i];
	                temp[j] -= rock[i];
	                dfs(temp[0], temp[1]);
	            }
	        }
	    }
	}
}

