import java.io.IOException;
import java.util.Scanner;

public class Main {

	static int[] time = new int[16];
	static int[] pay = new int[16]; 
	static int answer=0;

	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		for(int i=1; i<=n; i++) {
			time[i] = sc.nextInt();
			pay[i] = sc.nextInt();
		}

		// 상담이 퇴사 후에 끝남 -> 오늘 상담 불가능
		if(1+time[1] > n+1) {
			dfs(2, 0, n);
		}

		else {
			//첫날 상담 O
			dfs(1+time[1], pay[1], n);

			//첫날 상담 X
			dfs(2, 0, n);
		}

		System.out.println(answer);
	}

	public static void dfs(int nowTime, int totalPay, int n) {

		if(nowTime > n) {
			if(answer < totalPay) {
				answer = totalPay;

			}
			return ;
		}

		// 상담이 퇴사 후에 끝남 -> 오늘 상담 불가능
		if(nowTime+time[nowTime] > n+1) {
			if(answer < totalPay) {
				answer = totalPay;

			}
			dfs(nowTime+1, totalPay, n);
		}

		// 오늘 상담 가능 
		else {
			// 오늘 상담 O 
			dfs(nowTime+time[nowTime], totalPay+pay[nowTime], n);
			// 오늘 상담 X
			dfs(nowTime+1, totalPay, n);
		}


	}

}
