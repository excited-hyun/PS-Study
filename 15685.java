import java.util.*;

public class Main {

	static int n;
	static int[][] map = new int[101][101];
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int answer = 0;
		
		n = sc.nextInt();
		
		// 드래곤커브 생성 
		for(int i=0; i<n; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int d = sc.nextInt();
			int g = sc.nextInt();
			
			makeDragon(x, y, d, g);
		}
		
		//사각형 수 세기
		int[] R = {0, 1, 1};
		int[] C = {1, 0, 1};
		for(int i=0; i<100; i++) {
			for(int j=0; j<100; j++) {
				if(map[i][j] == 0)
					continue;
				
				int cnt = 0;
				for(int k=0; k<3; k++) {
					int newR = i + R[k];
					int newC = j + C[k];
					if(map[newR][newC] == 1)
						cnt++;
					else
						break;
				}
				
				if(cnt == 3)
					answer++;
			}
		}
		
		System.out.println(answer);
	}
	
	static void makeDragon(int x, int y, int d, int g) {
		LinkedList<Integer> l1 = new LinkedList<>();
		
		int[] R = {0, -1, 0, 1};
		int[] C = {1, 0, -1, 0};
		
		// 진행방향 순서대로 저장 
		l1.add(d);
		for(int i=1; i<=g; i++) {
			for(int j=l1.size()-1; j>=0; j--) {
				int newD = (l1.get(j)+1) % 4;
				l1.add(newD);
			}
		}
		
		int nowX = x;
		int nowY = y;
		//방향에 맞게 좌표 저장
		for(int i=0; i<l1.size(); i++) {
			if(nowX>=0 && nowY>=0 && nowX <= 100 && nowY <= 100 )
				map[nowY][nowX] = 1;
			nowX = nowX + C[l1.get(i)];
			nowY = nowY + R[l1.get(i)];
			
		}
		
		if(nowX>=0 && nowY>=0 && nowX <= 100 && nowY <= 100 )
			map[nowY][nowX] = 1;
		
	}
	
	
	
}


