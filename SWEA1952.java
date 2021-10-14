import java.util.Scanner;

public class Solution {
	static int day;
	static int oneMon;
	static int threeMon;
	static int year;
	static int[] plan = new int[13];
	static int answer;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		for(int tc=1; tc<=T; tc++) {
			day = sc.nextInt();
			oneMon = sc.nextInt();
			threeMon = sc.nextInt();
			year = sc.nextInt();

			for(int i=1; i<=12; i++) {
				plan[i] = sc.nextInt();
			}

			// 1년 단위 등록 
			answer = year;

			dfs(1, 0);

			System.out.println("#"+tc+" "+answer);
		}

	}

	static void dfs(int month, int cost) {
		
		if(month > 12) {
			if(cost < answer)
				answer = cost;
			return;
		}

		//이번달에 이용함 
		if(plan[month] > 0) {
			//1일 이용권
			dfs(month+1, cost + day * plan[month]);

			//1달 이용권
			dfs(month+1, cost+oneMon);
			
			//3달 이용권
			dfs(month+3, cost+threeMon);
		}
		
		//이용안함 
		else {
			dfs(month+1, cost);
		}
		
	}

}

