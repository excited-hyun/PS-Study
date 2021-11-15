import java.util.Scanner;

public class Main {

	static char[][] map;
	static int[][] visited = new int[50][50];
	static int[] X = {1, -1, 0, 0};
	static int[] Y = {0, 0, 1, -1};
	static int s_x, s_y, cnt, sw;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n, m;
	    n = sc.nextInt();
	    m = sc.nextInt();
	    
	    map = new char[n][m];
	    
	    for(int i=0; i<n; i++){
	         String s = sc.next();
	         for(int j=0; j<m; j++)
	        	 map[i][j] = s.charAt(j);
	        	 
	    }
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            
	            cnt = 0;
	            s_x = i;
	            s_y = j;
	            dfs(i, j, n, m);
	        }
	    }
	    if(sw==1)
	    	System.out.println("Yes\n");
	    else
	    	System.out.println("No\n");
	}
	
	static void dfs(int x, int y, int n, int m){
	    int next_x, next_y;
	    
	    visited[x][y] = 1;
	    
	    cnt++;
	    
	    for(int i=0; i<4 ;i++){
	        next_x = x+X[i];
	        next_y = y+Y[i];
	        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >=m)
	            continue;
	        if(map[next_x][next_y] != map[x][y])
	            continue;
	        if(visited[next_x][next_y] == 1  && next_x==s_x && next_y==s_y && cnt > 3){
	            sw = 1;
	            return;
	        }
	        if(visited[next_x][next_y] == 1)
	            continue;
	        
	        dfs(next_x, next_y, n,m);
	    }
	    visited[x][y] = 0;
	    cnt --;
	}

}

