import java.util.Scanner;
import java.util.*;

public class Main {
	static int N, M;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);	
		N = sc.nextInt();
		M = sc.nextInt();
		
		int cnt = 0;
		ArrayList<Room> [][] arr = new ArrayList[N+1][N+1];
		Queue<Room> q = new LinkedList<>();
		int[][] visited = new int[N+1][N+1];
		int[][] light = new int[N+1][N+1];
		int[] X = {1, -1, 0, 0};
		int[] Y = {0, 0, 1, -1};
		
		for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                arr[i][j] = new ArrayList<>();
            }
        }
		
		for(int i=0; i<M; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			arr[x][y].add(new Room(a, b));
		}
		
		q.add(new Room(1, 1));

		light[1][1] = 1;
		cnt++;
		// 이동 가능한 지점들 표시 
		int[][] canMove = new int[N+1][N+1];
		
		while(!q.isEmpty()) {
			Room now = q.poll();
			
			visited[now.x][now.y] = 1;
			
			//불 켜기 
			for(Room r : arr[now.x][now.y]) {
				if(light[r.x][r.y]== 1)
					continue;
				light[r.x][r.y]= 1;
				cnt++;
				if(canMove[r.x][r.y] == 1)
					q.add(new Room(r.x, r.y));
				
			}
			
			for(int i=0; i<4; i++) {
				int nextX = now.x+X[i];
				int nextY = now.y+Y[i];
				if(nextX<1 || nextX>N || nextY<1 || nextY>N)
					continue;
				
				canMove[nextX][nextY] = 1;
				
				//이미 방문했거나 불꺼진 방 
				if(visited[nextX][nextY] == 1 || light[nextX][nextY] == 0)
					continue;
				
				q.add(new Room(nextX, nextY));
			}
		}
		System.out.println(cnt);
		
	}
	
	static class Room {
		int x, y;
		
		Room (int x, int y){
			this.x = x;
			this.y = y;
			
		}
	}

}

