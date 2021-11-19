import java.util.*;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int[] arr = new int[N+1];
		
		for(int i=1; i<=N; i++)
			arr[i] = sc.nextInt();
		
		ArrayList<Integer> order = new ArrayList<>();
		
		order.add(N);
		for(int i=N-1; i>0; i--) {
			int bef = arr[i];
			order.add(bef, i);
		}
		
		for(int p : order)
			System.out.print(p+" ");
		
		System.out.println();

	}

}

