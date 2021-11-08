import java.util.Scanner;

public class Main {
	static int N, S;
	static int[] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		arr = new int[N+1];
		
		for(int i=1; i<=N; i++) {
			arr[i] = sc.nextInt();
		}
		S = sc.nextInt();
		
		for(int i=0; i<S; i++) {
			int gender = sc.nextInt();
			int num = sc.nextInt();
			
			//남자 
			if(gender == 1) {
				male(num);
			}
			//여
			else {
				female(num);
			}
			
		}
		
		for(int i=1; i<=N; i++) {
			System.out.print(arr[i]+" ");
			if(i%20 == 0) {
				System.out.println();
			}
		}
	
	}
	
	static void male(int num) {
		for(int i=1; i*num<=N; i++) {
			if(arr[i*num] == 1)
				arr[i*num] = 0;
			else
				arr[i*num] = 1;
		}
	}
	
	static void female (int num) {
		
		
		for(int i=0; i<N; i++) {
			if((num - i) < 1 || (num + i)>N)
				break;
			if(arr[num-i] != arr[num + i])
				break;
			
			if(arr[num-i] == 1) {
				arr[num-i] = 0;
				arr[num+i] = 0;
			}
			else {
				arr[num-i] = 1;
				arr[num+i] = 1;
			}
		}
			
			
	}

}

