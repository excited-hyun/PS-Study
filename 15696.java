import java.util.Scanner;

public class Main {

	static int chicken = 0;
	static int home = 0;
	static int n;
	static int m;
	
	static int[] chicR = new int[13];
	static int[] chicC = new int[13];
	
	static int[] homeR = new int[100];
	static int[] homeC = new int[100];
	
	static int answer;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				int input = sc.nextInt();
				//치킨집 
				if(input == 2) {
					chicR[chicken] = i;
					chicC[chicken] = j;
					chicken++;
				}
				//집 
				else if(input == 1) {
					homeR[home] = i;
					homeC[home] = j;
					home++;
				}
			}
		}
		
		answer = n*n*home;
		// 유지중인 치킨집 수, 연산할 치킨집 idx
		delChic(chicken, 0);
		
		System.out.println(answer);

	}

	// 삭제할 치킨집 선택
	static void delChic(int cnt, int idx) {
		if(cnt == m) {
			checkDist();
			return ;
		}
		// 삭제 덜 했는데 마지막 치킨집 도달 
		if(idx == chicken)
			return ;
		
		//현재 idx의 치킨집 위치 임시저장 
		int tempR = chicR[idx];
		int tempC = chicC[idx];
		
		// 현재 idx치킨집 삭제 O
		chicR[idx] = 0;
		chicC[idx] = 0;
		delChic(cnt-1, idx+1);
		
		// 삭제 X
		chicR[idx] = tempR;
		chicC[idx] = tempC;
		delChic(cnt, idx+1);
	}
	
	//치킨거리 측정 
	static void checkDist() {
		int sum = 0;
		
		for(int i=0; i<home; i++) {
			int nowC = homeC[i];
			int nowR = homeR[i];
			int minD = n*n;
			for(int j=0; j<chicken; j++) {
				//삭제한 치킨집
				if(chicR[j] == 0 && chicC[j] == 0)
					continue;
				int dist = Math.abs(nowC - chicC[j]) + Math.abs(nowR - chicR[j]);
				minD = Math.min(minD, dist);
			}
			sum+=minD;
		}
		if(answer > sum)
			answer = sum;
	}
}
