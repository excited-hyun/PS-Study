import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int total = n*n;
		int answer = 0;
		
		int [] order = new int[total];			//학생 앉히는 순서 
		int[][] friend = new int[total+1][4];	//좋아하는 친구 
		int[][] seat = new int[n][n];			//교실 자리  
		int[] moveR = {1, -1, 0, 0};
		int[] moveC = {0, 0, 1, -1};
		
		for(int i=0; i<n*n; i++) {
			int s = sc.nextInt();
			order[i] = s;
			friend[s][0] = sc.nextInt();
			friend[s][1] = sc.nextInt();
			friend[s][2] = sc.nextInt();
			friend[s][3] = sc.nextInt();
		}
		
		seat[1][1] = order[0];
		
		//학생 하나씩 앉히기 
		for(int i=1; i<total; i++) {
			
			int maxScore = -1;
			int r=-1, c=-1;
			int child = order[i];
			
			//전체 교실 확인
			for(int j=0; j<n; j++) {
				for(int k=0; k<n; k++) {
					if(seat[j][k] !=0 )
						continue;
					
					int score = 0;
					for(int s = 0; s<4; s++) {
						
						int checkR = j+moveR[s];
						int checkC = k+moveC[s];
						
						//범위 벗어
						if(checkR < 0 || checkR >=n || checkC < 0 || checkC >= n)
							continue;
						
						// 빈칸이면 score+1
						if(seat[checkR][checkC] == 0) {
							score++;
							continue;
						}
						
						for(int f=0; f<4; f++) {
							//좋아하는 친구면 score+10
							if(seat[checkR][checkC] == friend[child][f])
								score+=10;
						}
					}
					
					// 가중치 max값 업데이트 
					if(score > maxScore) {
						maxScore = score;
						r = j;
						c = k;
					}
					
				}
			}
			seat[r][c] = child;
		}
		
		//만족도 계산 
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				int cnt = 0;
				int child = seat[j][k];
				for(int s = 0; s<4; s++) {
					int checkR = j+moveR[s];
					int checkC = k+moveC[s];
					
					//범위 벗어
					if(checkR < 0 || checkR >=n || checkC < 0 || checkC >= n)
						continue;
					
					for(int f=0; f<4; f++) {
						//좋아하는 친구면
						if(seat[checkR][checkC] == friend[child][f])
							cnt++;
					}
				}
				if (cnt == 1)
					answer+=1;
				else if (cnt == 2)
					answer+=10;
				else if (cnt == 3)
					answer+=100;
				else if (cnt == 4)
					answer+=1000;
				
			}
		}
		System.out.println(answer);
		

	}

}

