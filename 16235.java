import java.util.Scanner;
import java.util.*;

public class Main {

	static int[][] map = new int[11][11];		//각 땅의 양
	static int[][] A = new int[11][11];			//S2D2가 추가하는 양분 
		
	static int n, m, k;
	
	static int[] R = {1,-1,0,0,1,-1,1,-1};
	static int[] C = {0,0,1,-1,1,1,-1,-1};
	
	static PriorityQueue<Tree> q1 = new PriorityQueue <>();		//나무 저장 
	static PriorityQueue<Tree> die = new PriorityQueue <>();	//나무가 죽어 여름에 추가될 양분 
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		m = sc.nextInt();
		k = sc.nextInt();
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				A[i][j] = sc.nextInt();
				map[i][j] = 5;
			}
		}
		
		for(int i=0; i<m; i++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int age = sc.nextInt();
		
			q1.add(new Tree(r, c, age));
		}
		
		for(int year=0; year<k; year++) {
			
			PriorityQueue<Tree> q2 = new PriorityQueue <>();	//임시로 사용하는 pq 
			// 봄 : 양분 먹거나 나무 die
			while(!q1.isEmpty()) {
				int r = q1.peek().r;
				int c = q1.peek().c;
				int age = q1.peek().age;
				q1.remove();
				//양분 먹음 
				if(map[r][c] >= age) {
					q2.add(new Tree(r, c, age+1));
					map[r][c] -= age;
				}
				//나무 죽음
				else {
					die.add(new Tree(r, c, age/2));
				}
			}
			
			
			// 여름 : die 나무 양분으로 
			for(Tree t :die){
				int r = t.r;
				int c = t.c;
				int age = t.age;
				map[r][c] += age;
			}
			die.clear();
			
			// 가을 : 번식 
			while(!q2.isEmpty()) {
				int r = q2.peek().r;
				int c = q2.peek().c;
				int age = q2.peek().age;
				q2.remove();
				q1.add(new Tree(r, c, age));
				
				//나무 나이가 5의 배수
				if(age%5 == 0) {
					for(int i=0; i<8; i++) {
						int newR = r+R[i];
						int newC = c+C[i];
						if(newR<=0 || newR>n || newC<=0 || newC>n)
							continue;
						
						q1.add(new Tree(newR, newC, 1));
					}
				}
				
			}
			
			// 겨울 : S2D2가 양분 추가 
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					map[i][j] += A[i][j];
				}
			}
		}
		
		int answer = q1.size();
		
		System.out.println(answer);
	}
	
	
	static class Tree implements Comparable<Tree> {
	    int r, c, age;
	    
	    Tree(int r, int c, int age) {
	        this.r = r;
	        this.c = c;
	        this.age = age;
	    }
	    
	    public int compareTo(Tree t) {
	    	return Integer.compare(this.age, t.age);
	    }
	}
}

