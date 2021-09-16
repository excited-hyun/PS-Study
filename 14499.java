import java.util.Scanner;

public class Main {
	static int[][] map = new int[20][20];
	static int[] X = {0, 0, 0, -1, 1};
	static int[] Y = {0, 1, -1, 0, 0};
	static int[] dice =  new int[6]; 

	public static void main(String[] args) {
		int n, m, x, y, k;
	    Scanner sc = new Scanner(System.in);
	    
	    n = sc.nextInt();
	    m = sc.nextInt();
	    x = sc.nextInt();
	    y = sc.nextInt();
	    k = sc.nextInt();
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            map[i][j] = sc.nextInt();
	        }
	    }
	    
	    int move;
	    int now = 6;
	    int up = 1;
	    for(int i=0; i<k; i++){
	        move = sc.nextInt();
	        int newX = x+X[move];
	        int newY = y+Y[move];
	        int[] temp = new int[6];
	        
	        if(newX<0 || newX>=n || newY<0 || newY>=m)
	            continue;
	        
	        //동
	        if(move == 1){
	            for(int j=0; j<6; j++) {
	            	temp[j] = dice[j];
	            }
	            dice[0] = temp[3];
	            dice[1] = temp[1];
	            dice[2] = temp[0];
	            dice[3] = temp[5];
	            dice[4] = temp[4];
	            dice[5] = temp[2];
	            
	        }
	        //서
	        else if(move == 2){
	        	for(int j=0; j<6; j++) {
	            	temp[j] = dice[j];
	            }
	            dice[0] = temp[2];
	            dice[1] = temp[1];
	            dice[2] = temp[5];
	            dice[3] = temp[0];
	            dice[4] = temp[4];
	            dice[5] = temp[3];
	        }
	        
	        //남
	        else if(move == 3){
	        	for(int j=0; j<6; j++) {
	            	temp[j] = dice[j];
	            }
	            dice[0] = temp[1];
	            dice[1] = temp[5];
	            dice[2] = temp[2];
	            dice[3] = temp[3];
	            dice[4] = temp[0];
	            dice[5] = temp[4];
	        }
	        //북
	        else if(move == 4){
	        	for(int j=0; j<6; j++) {
	            	temp[j] = dice[j];
	            }
	            dice[0] = temp[4];
	            dice[1] = temp[0];
	            dice[2] = temp[2];
	            dice[3] = temp[3];
	            dice[4] = temp[5];
	            dice[5] = temp[1];
	        }
	        
	        if(map[newX][newY] == 0){
	            map[newX][newY] = dice[5];
	            
	        }
	        else{
	            dice[5] = map[newX][newY];
	            map[newX][newY] = 0;
	        }
	        
	        System.out.println(dice[0]);
	        
	        x = newX;
	        y = newY;
	    }
	    

	}

}

