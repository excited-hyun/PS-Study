import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[] wine = new int[n+1];
		int[] dp = new int[n+1];
		
		for(int i=1; i<=n; i++)
			wine[i] = sc.nextInt();
		
		dp[0] = 0;
		dp[1] = wine[1];
		
		// n==1일 수도 있음!!!!
		if(n>1)
			dp[2] = dp[1] + wine[2];
		
		
		for(int i = 3; i<=n; i++) {
			dp[i] = Math.max(dp[i-1], dp[i-2]+wine[i]);
			dp[i] = Math.max(dp[i], dp[i-3]+wine[i]+wine[i-1]);
		}
		
		System.out.println(dp[n]);
		
	}
}

