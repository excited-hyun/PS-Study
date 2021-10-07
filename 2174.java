import java.util.Scanner;

public class Main {
	static int A, B;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		A = sc.nextInt();
		B = sc.nextInt();
		
		int N, M;
		N = sc.nextInt();
		M = sc.nextInt();
		
		int[][] map = new int[B+1][A+1];
		
		Robot[] arr = new Robot[N];
		
		for(int i=0; i<N; i++) {
			int c = sc.nextInt();
			int r = sc.nextInt();
			String dir = sc.next();
			
			arr[i] = new Robot(r, c, dir.charAt(0));
			map[r][c] = i+1;
			
		}
		
		for(int i=0; i<M; i++) {
			int idx = sc.nextInt();
			String com = sc.next();
			int re = sc.nextInt();
			
			//앞으로 이동 
			if(com.charAt(0) == 'F') {
				int nowR = arr[idx-1].r;
				int nowC = arr[idx-1].c;
				char nowDir = arr[idx-1].dir;
				map[nowR][nowC] = 0;
				
				for(int j=0; j<re; j++) {
					//System.out.println(nowR+" "+nowC);
					if(nowDir == 'N') {
						nowR++;
					}
					else if(nowDir == 'W') {
						nowC--;
					}
					else if(nowDir == 'E') {
						nowC++;
					}
					else if(nowDir == 'S') {
						nowR--;
					}
					
					//벽에 충돌!
					if(nowR<=0 || nowR>B || nowC<=0 || nowC>A) {
						System.out.println("Robot "+idx+" crashes into the wall");
						return ;
					}
					//다른 로봇과 충돌!
					else if(map[nowR][nowC] != 0) {
						System.out.println("Robot "+idx+" crashes into robot "+map[nowR][nowC]);
						return ;
					}
					
					
				}
				map[nowR][nowC] = idx;
				arr[idx-1].r = nowR;
				arr[idx-1].c = nowC;
			}
			
			//왼쪽 회전 
			else if(com.charAt(0) == 'L') {
				int change = re%4;
				for(int j=0; j<re; j++) {
					char nowDir = arr[idx-1].dir;
					if(nowDir == 'N') {
						arr[idx-1].dir = 'W';
					}
					else if(nowDir == 'W') {
						arr[idx-1].dir = 'S';
					}
					else if(nowDir == 'E') {
						arr[idx-1].dir = 'N';
					}
					else if(nowDir == 'S') {
						arr[idx-1].dir = 'E';
					}
				}
			}
			//오른쪽 회전 
			else if(com.charAt(0) == 'R') {
				int change = re%4;
				for(int j=0; j<change; j++) {
					char nowDir = arr[idx-1].dir;
					if(nowDir == 'N') {
						arr[idx-1].dir = 'E';
					}
					else if(nowDir == 'W') {
						arr[idx-1].dir = 'N';
					}
					else if(nowDir == 'E') {
						arr[idx-1].dir = 'S';
					}
					else if(nowDir == 'S') {
						arr[idx-1].dir = 'W';
					}
				}
			}
		}
		
		System.out.println("OK");

	}
}

class Robot{
	int r, c;
	char dir;
	
	Robot(int r, int c, char dir){
		this.r = r;
		this.c = c;
		this.dir = dir;
		
	}
}

